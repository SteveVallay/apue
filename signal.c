#include "apue.h"
#include <sys/wait.h>
#include <signal.h>

#define BUF_SIZE 1024

static void signal_h(int sig){
    printf("interrupted by %d\n%% ", sig);
    fflush(stdout);
}

int main(void)
{
   char buf[MAXLINE];
   pid_t pid;
   int status = 0;

   printf("%% ");
   if (signal(SIGINT,signal_h) == SIG_ERR) {
       printf("signal error!\n ");
   }
   while (fgets(buf, MAXLINE, stdin) != NULL)
   {
       /*replace last character to \0 */
       int n = strlen(buf);
       if (buf[n-1] == '\n'){
           buf[n-1] = 0;
       }else{
           printf("last char is %d",buf[n-1]);
       }

       /*call the command:*/
       pid = fork();
       if (0 == pid){
           printf("returned in child process pid is %d \n",pid);
           execlp(buf,buf,(char*)0);
           err_ret("couldn't execute %s\n",buf);
           exit(127);

       } else if ( pid > 0 ) {
           printf("return  in parent process pid is %d \n",pid);
           if ((pid = waitpid(pid,&status,0)) == -1)
               err_sys("error waitpid status is %d\n",status);
           else
               printf("waitpid status is %d\n",status);
       } else {
           err_sys("fork error\n");
       }
       printf("%% ");
   }

   exit(0);
}
