/**
 * APUE sample code of 4.3 , print type of the file for each command line.
 * date: 2013/11/29 22:11:09
 * author: zhibin
 * mail: zhibinwang.q@gmail.com
 */

#include "apue.h"

int main (int argc, char* argv[]){
    if (argc < 2){
        printf("Usage: file-type  file1 file2 ...\n");
        exit(1);
    }

    int i = 1;
    struct stat buf;
    char *ptr;
    for (;i < argc;i++) {
        printf("%s ", argv[i]);
        if (stat(argv[i],&buf)  == -1){
            err_ret("lstat failed !\n");
            continue;
        }

        mode_t mode = buf.st_mode;
        if (S_ISREG(mode)){
            ptr = "is regular file";
        } else if (S_ISDIR(mode)){
            ptr = "is directory";
        } else if (S_ISCHR(mode)) {
            ptr = "is char device";
        } else if (S_ISBLK(mode)) {
            ptr = "is block device";
        } else if (S_ISFIFO(mode)) {
            ptr = "is FIFO";
        } else if (S_ISLNK(mode)) {
            ptr = "is symbol link";
        } else if (S_ISSOCK(mode)) {
            ptr = "is socket";
        } else {
            ptr = "** unknown file type **";
        }
        printf("%s \n",ptr);
    }
    exit(0);
}

