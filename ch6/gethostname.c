#include "apue.h"
#include <unistd.h>
#define HOST_NAME_MAX 64
int main (int argc, char* argv[])
{
    char hostname[HOST_NAME_MAX];
    if (gethostname(hostname, HOST_NAME_MAX) < 0 )
    {
        err_quit("gethostname fail!\n");
    }
    printf("hostname:%s\n", hostname);
    return 0;
}
