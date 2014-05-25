#include "apue.h"

int main (int argc, char* argv[])
{
    int     c;
    while ((c =  getc(stdin)) != EOF)
        if((putc(c,stdout) == EOF))
            err_sys("output error\n");

    if(ferror(stdin))
            err_sys("stdin error\n");
    exit(0);
}

