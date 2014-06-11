#include "apue.h"
/*define main */
int main (int argc, char* argv[])
{
/*define char buff name with length L_tmpnam line MAXLINE*/
char name[L_tmpnam], line[MAXLINE];
/*define fp */
FILE *fp;
printf("tmpnam:%s\n",tmpnam(NULL));
tmpnam(name);
printf("name:%s\n",name);
if ((fp = tmpfile()) == NULL)
    err_sys("create tmpfile fail!\n");
if (fputs("put a new line", fp) < 0)
    err_sys("fputs to fp error!\n");
rewind(fp);
if (fgets(line, sizeof(line), fp) < 0)
    err_sys("fgets from fp error!\n");
if (fputs(line, stdout));
exit(0);
}


