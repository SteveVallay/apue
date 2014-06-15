#include "apue.h"
#include <sys/time.h>

int main (int argc, char* argv[])
{
    struct timeval cur;
    if (gettimeofday(&cur, NULL) < 0)
    {
        err_quit("gettimeofday fail !\n");
    }
    printf("tv_sec:%ld\n", cur.tv_sec);
    printf("tv_usec:%ld\n", cur.tv_usec);
    return 0;

}
