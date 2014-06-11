/*no tmpnam(const char* dir, const char* prefix) in linux */
/*
#include "apue.h"
int main(int argc, char* argv[])
{
    if (argc != 3)
        err_quit("usage: tmpfile2 <directory> <prefix> \n");
    printf("%s\n", tmpnam(argv[1][0] != ' '? argv[1]:NULL, argv[2][0] != ' ' ? argv[2]:NULL));
    exit(0);
}
*/
