#ifndef _SERVER
#define _SERVER
#include "general.h"

typedef struct server
{
    MySocket broadcast_list[20];
    int qtd;
}Server;



void init_server(MySocket * ms, int n_clients);
void run_chat_server(MySocket *ms);
void broadcast_server(MySocket * ms);
#endif