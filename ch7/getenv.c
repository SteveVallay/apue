#include "apue.h"
int main (int argc, char* argv[])
{
    char* ptr;
    if ((ptr = getenv("USER")) == NULL)
        printf("getenv fail!\n");
    printf("USER=%s\n", ptr);
    return 0;
}
