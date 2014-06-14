#include "apue.h"
#include <grp.h>
int main(int argc, char* argv[])
{
    struct group *ptr;
    ptr = getgrgid(1000);
    printf("name:%s,id:%d\n",ptr->gr_name,ptr->gr_gid);
    ptr = getgrnam("goodluck");
    printf("name:%s,id:%d\n",ptr->gr_name,ptr->gr_gid);
    /*get first grp name and gid*/
    setgrent();
    ptr = getgrent();
    printf("name:%s,id:%d\n",ptr->gr_name,ptr->gr_gid);
    endgrent();
    return 0;
}
