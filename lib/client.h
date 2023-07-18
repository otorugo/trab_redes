#ifndef _CLIENT
#define _CLIENT
#include "general.h"
#include <sys/socket.h>


struct client
{
    char nick[20];
    char message[MAX_BUFFER_SIZE+1];
};


void init_client(int port);




#endif