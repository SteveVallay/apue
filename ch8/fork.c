#include "apue.h"
int glob = 1;
char buf[] = "a write to stdout \n";

int main(void)
{
    int var;
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != (sizeof(buf) - 1))
        err_sys("write error \n");
    printf("before fork!\n");

    if ((pid = fork()) < 0){
        err_sys("fork error\n");
    } else if (pid == 0)
    {
        glob ++;
        var++;
    } else {
        sleep(2);
    }

    printf("pid=%d, var =%d, glob=%d \n", getpid(), var, glob);
    return 0;
}
