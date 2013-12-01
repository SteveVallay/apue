#include "apue.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        err_sys("Usage: access file\n");
    }
    char *path;
    path = argv[1];

    if (access(path,R_OK) < 0) {
        printf("Can not access %s as read \n", path);
    } else {
        printf("Can access %s as read \n", path);
    }

    if (open(path, O_RDONLY) < 0) {
        printf("Can not  open %s for read \n", path);
    } else {
        printf("Can open %s for read \n", path);
    }
    exit(0);
}
