#ifndef _CLIENT
#define _CLIENT
#include "general.h"
// #include <sys/socket.h>

MySocket init_client_fd(int port, int fd);
void run_client(MySocket *ms);
#endif