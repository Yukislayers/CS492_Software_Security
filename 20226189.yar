// CS492 - Homework4
// 20226189 - Kau Anthony Mathieu

rule NumberSocketCall
{
        strings:
                // This rule is triggered when the number of socket_call
                // is superior than a certain value
                $hex_syscall_socket = { (B0 | B4 | B8)  66 } // mov (eax,ax,al), 0x66
                // mov (eax,ax,al), 0x66
                $hex_xor_syscall_socket1 = "\xB0\x66" xor
                $hex_xor_syscall_socket2 = "\xB4\x66" xor
                $hex_xor_syscall_socket3 = "\xB8\x66" xor

        condition:
                // socket_creation
                // socket_connect
                // socket_send
                // at least those 3 are used
                #hex_syscall_socket >= 3 or ($hex_xor_syscall_socket1 or $hex_xor_syscall_socket2 or $hex_xor_syscall_socket3)
}

rule IpAddress
{
        strings:
                // This string is for the struct address when
                // you are pushing the IP address in the server
                // struc that you will use for socket creation
                $hex_xor_ipaddress_struct = "\x8f\xf8\x26\xd4" xor
                $hex_ipaddress_struct = { b8 8f f8 26 d4 }


        condition:
                $hex_xor_ipaddress_struct or $hex_ipaddress_struct
}

rule HttpRequest
{
        strings:
                //This is to match the "GET /cs492e.txt HTTP/1.0\r\n\r\n"
                //that we send to the socket to get the command of the
                //botnet
                $hex_http_request_1 = { 68 0D 0A 0D 0A } // \r\n\r\n
                $hex_http_request_2 = { 68 2f 31 2e 30} // 0.1/
                $hex_http_request_3 = { 68 48 54 54 50 } // PTTH
                $hex_http_request_4 = { 68 74 78 74 20 } //  txt
                $hex_http_request_5 = { 68 39 32 65 2E } // .e29
                $hex_http_request_6 = { 68 2F 63 73 34 } // 4sc/
                $hex_http_request_7 = { 68 47 45 54 20 } //  TEG

                $hex_xor_http_request_1 = "\x0D\x0A\x0D\x0A" xor
                $hex_xor_http_request_2 = "\x2F\x31\x2E\x30" xor
                $hex_xor_http_request_3 = "\x48\x54\x54\x50" xor
                $hex_xor_http_request_4 = "\x74\x78\x74\x20" xor
                $hex_xor_http_request_5 = "\x39\x32\x32\x34" xor
                $hex_xor_http_request_6 = "\x2F\x63\x73\x34" xor
                $hex_xor_http_request_7 = "\x47\x45\x54\x20" xor


        condition:
                ($hex_http_request_1 and $hex_http_request_2 and $hex_http_request_3 and $hex_http_request_4 and $hex_http_request_5 and $hex_http_request_6 and $hex_http_request_7) or ($hex_xor_http_request_1 and $hex_xor_http_request_2 and $hex_xor_http_request_3 and $hex_xor_http_request_4 and $hex_xor_http_request_5 and $hex_xor_http_request_6 and $hex_xor_http_request_7)
}

rule InfectedString 
{
        strings:
                $hex_infected_string = { 68 63 74 65 64 68 69 6E 66 65}
                $hex_xor_infected_string1 = "\x63\x74\x65\x64" xor
                $hex_xor_infected_string2 = "\x69\x6E\x66\x65" xor

        condition:
                $hex_infected_string or ($hex_xor_infected_string1 and $hex_xor_infected_string2)
}