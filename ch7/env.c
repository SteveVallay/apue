#include "apue.h"
extern char** environ;
int main(int argc, char* arg[])
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
        printf("environ[%d]: %s\n", i, environ[i]);
    return 0;
}
