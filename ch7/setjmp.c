#include "apue.h"
#include <setjmp.h>

#define ADD_TOKEN 5

jmp_buf jmpbuf;

void do_line(char*);
void cmd_add(void);
int get_token(void);

int main(int argc, char* argv[])
{
    char line[MAXLINE];
    if (setjmp(jmpbuf) != 0){
        printf("error\n");
    }
    while(fgets(line, MAXLINE, stdin) != NULL)
        do_line(line);
    return 0;
}

char* token_ptr;
