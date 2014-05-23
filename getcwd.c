#include "apue.h"
#include <unistd.h>


int main (int argc, char* argv[])
{
    char *ptr;
    int size;

    if (chdir("/var/log/news/") < 0)
        err_sys("chdir /var/log/news failed\n");

    ptr = path_alloc(&size);

    if (getcwd(ptr, size) == NULL)
        err_sys("get cwd error \n");

    printf("cwd  is : %s \n", ptr);
    exit(0);
}
