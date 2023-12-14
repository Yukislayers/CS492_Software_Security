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
        mov dx, 0x400   ; we want to read 1024 bytes
        mov ecx, esi    ; we had the buffer in esi
        mov ebx, edi    ; the file descriptor was stored in edi
        int 0x80        ; syscall for sys_read

; we want to write the message on the standard output
; write (int fd, const void *buf, size_t count)
        xor edx, edx
        mov dl, 0x01    ; We want to write only 1 byte from the buffer
        lea ecx, [esi + 0xf7] ; the actual body of the buffer start at offset 0xf7
        mov bl, 0x1     ; 1 is the standard output
        mov al, 0x04    ; sys_write syscall
        int 0x80        ; syscall for sys_write

exit:
  xor eax, eax
  mov al, 0x01
  int 0x80
