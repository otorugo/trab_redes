#include "general.h"

void readLine(char *string)
{
    char c = 0;

    do
    {
        c = (char)getchar();

    } while (c == '\n' || c == '\r');

    int i = 0;

    do
    {
        string[i] = c;
        i++;
        c = getchar();
    } while (c != '\n' && c != '\r' && c != EOF);

    string[i] = '\0';
}

void add_nick(MySocket *ms, char *buffer)
{
    strcpy(ms->message, ms->nick);
    strcat(ms->message, " : ");
    strcat(ms->message, buffer);
}

void random_name(MySocket *cl)
{
    srand(time(0));
    char nomes[][5] = {"jose", "joao", "dara", "mara"};
    int pos = rand() % 4;
    int id = rand() % 10 + 49;
    strcpy(cl->nick, nomes[pos]);
    cl->nick[4] = (char)id;
    cl->nick[5] = '\0';
}

MySocket init_socket(int port)
{
    MySocket cl;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in serv;
    cl.servaddr = &serv;
    cl.servaddr->sin_family = AF_INET;
    cl.servaddr->sin_port = htons(port);
    cl.sockfd = sockfd;
    inet_aton("localhost", &cl.servaddr->sin_addr);
    random_name(&cl);

    return cl;
}
