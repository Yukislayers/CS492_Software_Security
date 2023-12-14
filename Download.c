#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int download(){
/*
This function creates a socket to connect to the web server at
"143.248.38.212", read a file named "cs492e.txt" stored in the
webserver.
*/

int socket_desc;
char *message;
char buffer[1024] = {0};

FILE *file = NULL;
struct sockaddr_in server;

server.sin_addr.s_addr = inet_addr("143.248.38.212");
server.sin_family = AF_INET;
server.sin_port = htons( 80 );

//create socket
socket_desc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (socket_desc == -1){
    printf("Could not create socket");
}

//connect to the server
 if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

//puts("Connected\n");

//Send requests
message = "GET /cs492e.txt HTTP/1.0\r\n\r\n";

 if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

//puts("Data Send\n");

//We read what the webserver's answer to our requests
read(socket_desc, buffer, 1024);
//printf("%s\n", buffer);

/*
We want to parse the answer to get rid of the HTTP header
An HTTP header always end with "\r\n\r\n" so we will try to find
this string in the answer of our http requests.
*/
char *content = strstr(buffer, "\r\n\r\n");
if (content != NULL){
        content +=4;
}
else {
        content = buffer;
}

printf("%s\n", content);

//Closing the socket
close(socket_desc);

//Get out of the function
return 0;
}

int main(int argc, char *argv[]){
download();
}