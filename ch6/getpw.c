#include "apue.h"
#include <pwd.h>
int main(int argc, char *argv[])
{
    struct passwd *ptr;
    ptr = getpwuid(0);
    printf("name: %s\n", ptr->pw_name);
    ptr = getpwnam("goodluck");
    printf("uid : %d\n",ptr->pw_uid);
    exit(0);

}
