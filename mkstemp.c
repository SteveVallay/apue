#include "apue.h"
int main(int argc, char* argv[])
{
    if (argc != 2)
        err_quit("usage: mkstemp <pathnameXXXXXX>\n");

    char name[MAXLINE];
    strcpy(name, argv[1]);
    if (mkstemp(name) == -1)
        err_sys("mkstemp fail!\n");
    printf("temp file name: %s\n",name);
    exit(0);
}
