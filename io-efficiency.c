#include "apue.h"
#define BUFFERSIZE 4096
int main(int argc, char** argv)
{
   if(argc != 2){
       err_sys("Usage io buf-size\n");
   }
   int n;
   long size = atol(argv[1]);
   char buf[size];

   while ((n = read(STDIN_FILENO,buf,size)) > 0 )
       if (write(STDOUT_FILENO, buf, n) != n)
           err_sys("write error!");
       if (n < 0)
          err_sys("read error!");

   exit(0);

}
