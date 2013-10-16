#include "apue.h"
int main(void)
{
    printf("current uid is: %d, gid is: %d\n",getuid(),getgid());
    exit(0);
}
