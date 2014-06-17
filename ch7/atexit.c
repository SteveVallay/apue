#include "apue.h"
void print(void)
{
    printf("inside print...\n");
}
int main(int argc, char* argv[])
{
    atexit(print);
    printf("in main\n");
    /*return 0;*/
    /*exit(0);*/
    /*_exit(0);*/
    _Exit(0);
}
