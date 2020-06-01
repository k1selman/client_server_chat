#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //sockets
#include <netinet/in.h> //af_inet -- address family

struct sockaddr_in serv; //main socket variable
int fd; //socket file descriptor
int conn; //connection file descriptor
char message[100] = ""; //to store messages sent by server


int main()
{
    fd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_port = htons(8096);

    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr); //bind client to localhost;
    connect(fd, (struct sockaddr *)&serv, sizeof(serv)); //connect client to the server

    while(1){
        printf("Enter a message: ");
        fgets(message, 100, stdin);
        send(fd, message, strlen(message), 0);
        //todo: add some breaking condtion?
    }

    return 0;
}
