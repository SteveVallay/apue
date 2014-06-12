#include "apue.h"
#include <shadow.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char* argv[]) {
    struct spwd * ptr;
    if (geteuid() != 0)
        err_quit("must call it with euid root\n");
    setspent();
    ptr = getspent();
    printf("name: %s\n", ptr->sp_namp);
    printf("name: %s\n", ptr->sp_pwdp);
    endspent();
    return 0;
}
