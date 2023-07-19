#include "client.h"

MySocket init_client_fd(int port, int fd)
{
    MySocket cl;
    struct sockaddr_in serv;
    cl.servaddr = &serv;
    cl.servaddr->sin_family = AF_INET;
    cl.servaddr->sin_port = htons(port);
    cl.sockfd = fd;
    inet_aton("localhost", &cl.servaddr->sin_addr);
};

void run_client(MySocket *ms)
{

    char buffer[1024];
    // char *buffer = (char *)malloc(4096);
    while (1)
    {
        bzero(buffer, sizeof(buffer));
        readLine(buffer);

        if (buffer[0] == EOF)
            break;

        add_nick(ms, buffer);
        printf("%s\n", ms->message);
        send(ms->sockfd, ms->message, strlen(ms->message), 0);

        bzero(buffer, sizeof(buffer));
        recv(ms->sockfd, buffer, sizeof(buffer), 0);
        printf("%s\n", buffer);
    }
    // free(buffer);
    close(ms->sockfd);
    printf("Disconnected from the server.\n");
}
