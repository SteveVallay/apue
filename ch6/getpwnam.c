#include "apue.h"
#include <stddef.h>
#include <string.h>
#include <pwd.h>

struct passwd *
getpwnam2(const char *name)
{
    struct passwd *ptr;
    setpwent();
    while((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break;
    endpwent();
    return ptr;
}
int main (int argc , char* argv[])
{
    struct passwd *ptr;
    ptr = getpwnam2("goodluck");
    printf("name: %s\n",ptr->pw_name);
    printf("uid: %d\n", ptr->pw_uid);
    printf("gid: %d\n", ptr->pw_gid);
    return 0;
}
