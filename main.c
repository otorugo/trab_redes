#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/general.h"
#include "lib/client.h"
#include "lib/server.h"

void menu()
{
    int op = 0;
    printf("-----------------------------------\n");
    printf("---Trabalho de redes---\n");
    printf("-----------------------\n");
    printf("---Selecione uma opcao---\n");
    printf("---(1) - modulo 1---\n");
    printf("---(2) - modulo 2---\n");
    printf("---(3) - modulo 3---\n");
    printf("-----------------------------------\n");
    printf("\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:

        MySocket ms = init_socket(6666);
        if (connect(ms.sockfd, (struct sockaddr *)ms.servaddr, sizeof(*ms.servaddr)) < 0)
        {
            init_server(&ms, 2);
            printf("Esperando Alguem entrar...\n");
            run_chat_server(&ms);
        }
        else
        {
            run_client(&ms);
        }

        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;

    default:
        printf("-----------------------------------\n");
        printf("----Bye bye-----\n");
        printf("-----------------------------------\n");

        break;
    }
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
