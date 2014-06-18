#include "apue.h"
#define KEY "USER"
int main(int argc, char* argv[])
{
    char *ptr;
    ptr = getenv("USER");
    printf("getenv USER=%s\n", ptr);
    putenv("USER=hacker");
    ptr = getenv("USER");
    printf("putenv USER=%s\n", ptr);
    setenv("USER","GL",0);
    ptr = getenv("USER");
    printf("setenv no rewrite USER=%s\n", ptr);
    setenv("USER","GL",1);
    ptr = getenv("USER");
    printf("setenv with rewrite USER=%s\n", ptr);
    unsetenv("USER");
    ptr = getenv("USER");
    printf("unsetenv USER=%s\n", ptr);
    return 0;

}
