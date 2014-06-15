#include "apue.h"
#include <sys/utsname.h>
int main (int argc, char* argv[])
{
    struct utsname name;
    struct utsname *pname = &name;
    if (uname(pname) < 0 )
    {
        err_quit("uname fail !\n");
    }
    /*print name info*/
    printf("sysname:%s\n",pname->sysname);
    printf("nodename:%s\n", pname->nodename);
    printf("release:%s\n", pname->release);
    printf("version:%s\n", pname->version);
    printf("machine:%s\n", pname->machine);
    return 0;
}
