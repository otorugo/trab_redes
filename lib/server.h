#ifndef _SERVER
#define _SERVER
#include "general.h"


void init_server(MySocket * ms, int n_clients);
void run_chat_server(MySocket *ms);

#endif