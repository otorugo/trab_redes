#include "server.h"

void init_server(MySocket *ms, int n_clients)
{
    if (bind(ms->sockfd, (struct sockaddr *)ms->servaddr, sizeof(*(ms->servaddr))) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(ms->sockfd, 1) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

void run_chat_server(MySocket *ms)
{
    int new_socket;
    int addr_len = sizeof(*ms->servaddr);
    if ((new_socket = accept(ms->sockfd, (struct sockaddr *)ms->servaddr, (socklen_t *)&addr_len)) < 0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    // char *buffer = (char *)malloc(4096);
    while (1)
    {
        bzero(buffer, sizeof(buffer));
        recv(new_socket, buffer, sizeof(buffer), 0);
        printf("%s\n", buffer);

        bzero(buffer, sizeof(buffer));
        readLine(buffer);
        add_nick(ms, buffer);
        printf("%s\n", buffer);
        send(new_socket, ms->message, strlen(ms->message), 0);
    }
    // free(buffer);
    close(new_socket);
    printf("[+]Client disconnected.\n\n");
}

// void broadcast_server(MySocket *ms)
// {
//     Server s;
//     s.qtd = 0;
//     init_server(ms, 20);

//     int addr_len = sizeof(*ms->servaddr);
//     while (1)
//     {
//         if ((new_socket = accept(ms->sockfd, (struct sockaddr *)ms->servaddr, (socklen_t *)&addr_len)) < 0)
//         {
//             perror("accept failed");
//             exit(EXIT_FAILURE);
//         }
//         s.broadcast_list[s.qtd] = init_client_fd(6667,new_socket);
//         s.qtd++;

        

//     }
// }