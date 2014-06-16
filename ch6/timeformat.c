#include "apue.h"
#include <time.h>

int main(int argc, char* argv[])
{
    struct tm *ptm;
    time_t cur;
    time(&cur);
    if ((ptm = localtime(&cur))  == NULL)
        err_quit("mktime fail!\n");
    if ((ptm = gmtime(&cur)) == NULL)
        err_quit("gmtime fail!\n");

    printf("tm_sec: %d\n", ptm->tm_sec);
    printf("tm_min: %d\n", ptm->tm_min);
    printf("tm_hour: %d\n", ptm->tm_hour);
    printf("tm_mday: %d\n", ptm->tm_mday);
    printf("tm_mon: %d\n", ptm->tm_mon);
    printf("tm_year: %d\n", ptm->tm_year);
    printf("tm_wday: %d\n", ptm->tm_wday);
    printf("tm_yday: %d\n", ptm->tm_yday);
    printf("tm_isdst: %d\n", ptm->tm_isdst);

    char * astime;
    if ((astime = asctime(ptm)) == NULL)
        err_quit("asctime fail!\n");
    printf("astime: %s\n", astime);

    char* st;
    st = ctime(&cur);
    printf("ctime string:%s",st);
    return 0;
}
