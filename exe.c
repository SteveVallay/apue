#include "apue.h"
#include <sys/wait.h>

#define BUF_SIZE 1024 
int main(void)
{
   int size = 100;

   char buf[BUF_SIZE];
   int status = 0;

   while(fgets(buf, size, stdin) != 0)
   {
       /*replace last character to \0 */
       int n = strlen(buf);
       printf("str is %s, len is %d",buf,n);
       buf[n-1] = 0;

       /*call the command:*/
       pid_t pid = fork();
       if (0 == pid){
           printf("returned in child process pid is %d \n",pid);
           execlp(buf,buf,(char*)0);
           exit(127);

       } else if ( pid > 0 ) {
           printf("return  in parent process pid is %d \n",pid);
           if ((pid = waitpid(pid,&status,0)) == -1)
               err_sys("error waitpid status is %d",status);
       } else {
           err_sys("fork error\n");
       }
   }

   exit(0);
}
