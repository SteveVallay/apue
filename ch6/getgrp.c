#include "apue.h"
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 16
int main(int argc, char* argv[])
{
    gid_t  grp[SIZE];
    int size;
    if ((size = getgroups(SIZE, grp)) < 0) 
    {
        err_quit("fail to get groups..\n");
    }
    int i = 0;
    for (;i<size;i++)
    {
        printf("%d\n",grp[i]);
    }

    return 0;
   
}
