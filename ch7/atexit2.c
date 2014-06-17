#include "apue.h"
static void my_exit1(void)
{
    printf("first exit handler\n");
}
static void my_exit2(void)
{
    printf("second exit handler\n");
}
int main (int argc, char* argv[])
{
    if (atexit(my_exit2) != 0)
        err_quit("can't register my_exit2 \n");
    if (atexit(my_exit1) != 0)
        err_quit("can't register my_exit1 \n");
    if (atexit(my_exit1) != 0)
        err_quit("can't register my_exit1 2\n");
    return 0;
}
