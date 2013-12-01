#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>

#define RWRWRW S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
int main(int argc , char* argv[]) {
    umask(0);
    if (creat("foo",RWRWRW) < 0) {
        err_sys("create foo fail!\n");
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar",RWRWRW) < 0) {
        err_sys("create bar fail !\n");
    }
    exit(0);
}
