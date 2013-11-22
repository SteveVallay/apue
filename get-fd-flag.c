#include "apue.h"
#include <fcntl.h>

int main(int argc, char* argv[]){
    if (argc !=  2)
        err_sys("Usage: ./get-fd-flag #fd \n");

    int fd = atoi(argv[1]);
    int flag;
    if ((flag = fcntl(fd,F_GETFL)) < 0 )
        printf("get file stats flag error \n");

    switch (flag & O_ACCMODE) {
        case O_RDONLY:
            printf(" read only \n");
            break;
        case O_WRONLY:
            printf(" write only \n");
            break;
        case O_RDWR:
            printf(" read and write \n");
            break;
        default:
            err_dump("unknown access mode !\n");
    }

    if (flag & O_APPEND)
        printf(" append flag set \n");

    if (flag & O_NONBLOCK)
        printf(" non block flag set \n");

    if (flag & O_SYNC)
        printf(" sync flag set \n");
    
    if (flag & O_RSYNC)
        printf(" rsync flag set \n");

    if (flag & O_DSYNC)
        printf(" dsync flag set \n");

#ifdef O_FSYNC
    printf(" O_FSYNC defined \n");
    if (flag & O_FSYNC)
        printf(" fsync flag set \n");
#endif
    
#ifdef O_ASYNC
    printf(" O_ASYNC defined \n");
    if (flag & O_FSYNC)
        printf(" async flag set \n");
#endif

    exit(0);
    
}
