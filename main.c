#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //sockets
#include <netinet/in.h> //af_inet -- address family

//SERVER

struct sockaddr_in serv; //main socket variable
int fd; //socket file descriptor
int conn; //connection file descriptor
char message[100] = ""; //to store messages sent by server


int main()
{
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8096); //def the port at which server will isten for connections
    serv.sin_addr.s_addr = INADDR_ANY;

    fd = socket(AF_INET, SOCK_STREAM, 0); //new socket

    //todo: add something to handle errors

    bind(fd, (struct sockaddr *)&serv, sizeof(serv));
    listen(fd,5); //listen for connections, up to 5 permitted

    //handle the connections

    while(conn = accept(fd, (struct sockaddr *)NULL,NULL)){
    int pid;
        if((pid = fork()) == 0){
            while(recv(conn, message, 100, 0)>0){
                printf("Message received: %s\n", message);
                message == "";
            }
            exit(0);
        }

    }

    return 0;
}
