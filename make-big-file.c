#include "apue.h"
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        err_sys("Usage: make-big-file size >filename \n");
    }
    long size = atol(argv[1]);
    while(size > 0){
        int n = write(STDOUT_FILENO,"a",1);
        if (n < 0) {
            err_sys("write error!");
        }
        size--;
    }

    exit(0);

}
