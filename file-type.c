/**
 * APUE sample code of 4.3 , print type of the file for each command line.
 * date: 2013年 11月 29日 星期五 06:28:02 CST
 * author: zhibin
 * mail: zhibinwang.q@gmail.com
 */

#include "apue.h"

int main (int argc, char* argv[]){
    if (argc < 2){
        printf("Usage: file-type  file1 file2 ...");
        exit(1);
    }

    int i = 1;
    struct stat buf;
    for (;i < argc;i++) {

        if (lstat(argv[i],&buf)  == -1){
            err_sys("fail to get stat of the file %s\n",argv[i]);
        }

        mode_t mode = buf.st_mode;
        if (S_ISREG(mode)){
            printf("%s is regular file \n", argv[i]);
        } else if (S_ISDIR(mode)){
            printf("%s is directory \n", argv[i]);
        } else {
            printf("%s : unknown file type \n", argv[i]);
        }
    }
    exit(0);
}

