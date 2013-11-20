#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

#define TRUE 1;
#define FALSE 0;
int hole = TRUE;

int main(int argc , char* argv[]) {
    int fd;
    if(argc > 1){
        hole = FALSE;
    }
    char* name;
    if (hole){
        name = "file.hole";
    } else {
        name = "file.nohole";
    }
    if ((fd = creat(name,FILE_MODE)) < 0)
        err_sys("create error!");
    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");

    if (hole && lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");

    if(write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");

    exit(0);
}

