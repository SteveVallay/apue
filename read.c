#include "apue.h"
#include <unistd.h>

#define SIZE  16394

char buf[SIZE];
int main(void){
 int size;
 size = read(STDIN_FILENO,buf,SIZE);
 printf("size: %d\n",size);
 printf("buf is: %s\n",buf + 16384);
 exit(0);
}
