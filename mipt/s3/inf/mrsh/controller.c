#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include "common.h"
#include "multicast.h"

#define CMDERROR "fuck you!\n"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s REAL_IFACE_IP\n", argv[0]);
        return(1);
    }

    multicastInitTx(argv[1]);

    broadcastMessage bm;
    size_t size;

    int error = 0;

    for(;;)
    {
        if((size = read(STDIN_FILENO, bm.command, MCOMMAND - 1)) > 0)
        {
            if(bm.command[size - 1] != '\n')
            {
                write(STDOUT_FILENO, CMDERROR, sizeof(CMDERROR) - 1);
                error = 2;
            }
            else if(error > 0) error--;
            if(error == 0)
            {
                bm.command[size - 1] = 0;
                fprintf(stderr, "[%s]\n", bm.command);
            }
        }
    }
}
