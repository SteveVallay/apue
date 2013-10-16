#include "apue.h"
#include <dirent.h>
#include <errno.h>

int main(void){

    DIR *dir = NULL;

    if ((dir = opendir("error")) == NULL){
        printf("can not open dir error, error number is %d\n", errno);
        printf("strerror msg: %s\n",strerror(errno));
        perror("can not open error");
        exit(1);
    }

    exit(0);

}
