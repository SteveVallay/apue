#include "apue.h"
#include <unistd.h>

int main(int argc, char*argv[])
{
    if (argc != 2) 
        err_sys("Usage chdir <path>  \n");
    if (chdir(argv[1]) < 0)
        err_sys("chdir error: %s \n", argv[1]);
    printf("chdir to %s success \n", argv[1]);
    return 0;

}
