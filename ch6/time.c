#include "apue.h"
#include <time.h>

int main (int argc, char* argv[])
{
    time_t current;
    if (time(&current) < 0 )
        err_quit("get current time fail !\n");
    printf("current time: %ld\n",current);
    return 0;
}

