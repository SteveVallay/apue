#include "apue.h"
#include <unistd.h>

#define SIZE  100

char buf[SIZE];
int main(void){
 int size;
 size = read(STDIN_FILENO,buf,SIZE);
 printf("size: %d\n",size);
 printf("buf is: %s\n",buf);
 exit(0);
}
