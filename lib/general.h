#ifndef _GENERAL
#define _GENERAL
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define MAX_BUFFER_SIZE 4096


typedef struct mySocket
{
    char nick[6];
    char message[MAX_BUFFER_SIZE+1];
    struct sockaddr_in *servaddr;
    int sockfd;
}MySocket;

MySocket init_socket(int port);
void random_name(MySocket *cl);

void readLine(char *string);
void add_nick(MySocket *ms, char *buffer);


#endif