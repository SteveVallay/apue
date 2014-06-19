#include "apue.h"
int main (int argc, char* argv[])
{
    printf("pid=%d\n", getpid());
    printf("ppid=%d\n", getppid());

    printf("uid=%d\n", getuid());
    printf("euid=%d\n", geteuid());

    printf("gid=%d\n", getgid());
    printf("egid=%d\n", getegid());
    return 0;
}
