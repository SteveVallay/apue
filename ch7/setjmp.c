#include "apue.h"
#include <setjmp.h>

#define TOK_ADD 5

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

static int count = 0;
void do_line(char* ptr)
{
    int cmd;
    token_ptr = ptr;
    while ((cmd = get_token()) > 0) {
            printf("cmd is %d", cmd);
            switch (cmd) {
              case TOK_ADD:
                  cmd_add();
                  break;
            }
        }
}
void cmd_add(void)
{   /*
    int token;
    token = get_token();
    if (token < 0)
        longjmp(jmpbuf,1);
        */
    printf("cmd add..");
    if (count < 1)
        longjmp(jmpbuf,1);
}
int get_token(void)
{
    return atoi(token_ptr);
}
