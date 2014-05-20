#include "apue.h"
#include<unistd.h>

int main(int argc, char*argv[]){
    /*create a new link*/
    int ret = symlink("no/such/file","mylink");
    printf("make mylink: ret =%d\n",ret);
    ret = symlink("Makefile","mylink2");
    printf("make mylink again: ret =%d\n",ret);

    char buf[100];
    readlink("mylink2",buf,100);
    printf("mylink content: %s\n",buf);
    return 0;
    
}
