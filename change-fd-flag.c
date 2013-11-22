#include "apue.h"
#include <fcntl.h>

int s_fl(int fd, int flag);
int c_fl(int fd, int flag);

int main(int argc, char* argv[]){
    if (argc !=2 ){
        err_sys("Usage: change-file-flag #fd \n");
    }

    int fd = atoi(argv[1]);

    int flag;
    int set;
    if ((flag = fcntl(fd, F_GETFL)) < 0)
        err_sys("get file status error !\n");

    /* on Linux , access mode O_RDONLY, O_WRONLY , O_RDWR  and create flag 
     (O_CREAT , O_EXCL ,O_NCTTY, O_TRUNC) are ignored. Only O_APPEND,O_ASYNC,
     O_DIRECT, O_NOATIME and O_NONBLOCK can be changed.*/



    if (flag & O_APPEND) {
        set = 1;
        printf("append flag set \n");
    } else {
        set = 0;
        printf("append flag not set \n");
    }
    if (!set){
        if (s_fl(fd, O_APPEND) < 0)
            err_sys("set_fl failed \n");
        if ((flag = fcntl(fd, F_GETFL)) < 0 )
            err_sys("get new flag error \n");
        if (flag & O_APPEND)
            printf("set append flag success \n");
        else
            printf("set append flag fail \n");
    } else {
        if (c_fl(fd, O_APPEND) < 0)
            err_sys("unset_fl flag failed \n");

        if ((flag = fcntl(fd, F_GETFL)) < 0 )
            err_sys("get new flag error \n");

        if (!(flag & O_APPEND))
            printf("unset append flag success \n");
        else
            printf("unset append flag fail \n");
    }

    exit(0);

}

int s_fl(int fd, int flag){
   int var;
   if ((var = fcntl(fd, F_GETFL)) < 0)
       err_sys("get %d file status flag error!\n", fd);
   var |= flag;
   if (fcntl(fd, F_SETFL, var) < 0)
       err_sys("set %fd file status flag error !\n", fd);
   return 0;
}

int c_fl(int fd, int flag){
   int var;
   if ((var = fcntl(fd, F_GETFL)) < 0)
       err_sys("get %d file status flag error!\n", fd);
   var &= ~flag;
   if (fcntl(fd, F_SETFL, var) < 0)
       err_sys("set %fd file status flag error !\n", fd);
   return 0;
}
