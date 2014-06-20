#include "apue.h"

int glob = 1;

int main (int argc, char* argv[])
{
    int var = 88;
    pid_t pid;
    printf("before vfork!\n");

    if ((pid == vfork()) < 0) {
        err_sys("vfork error\n");
    } else if (pid == 0){
        glob++;
        var++;
        _exit(0);
    }
    printf("pid=%d, var =%d, glob=%d \n", getpid(), var, glob);
    exit(0);
}

