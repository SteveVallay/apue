#include "apue.h"
#define SIZE 20
int main(int argc ,char* argv[])
{
    char *ptr;
    if ((ptr = malloc(sizeof(char))) == NULL)
        printf("malloc fail!\n");
    *ptr = 'a';
    printf("ptr=%s-\n", ptr);
    printf("ptr:%p\n",ptr);
    free(ptr);
    if ((ptr = calloc(2,sizeof(char))) == NULL)
        printf("calloc fail!\n");
    *ptr = 'b';
    *(ptr+1) = 'c';
    printf("cptr=%s-\n",ptr);
    printf("ptr:%p\n",ptr);
    if ((ptr = realloc(ptr, 5*sizeof(char))) == NULL)
        printf("realloc fail\n");
    *(ptr+2) = '3';
    *(ptr+3)= '4';
    printf("rptr = %s\n", ptr);
    printf("ptr:%p\n",ptr);
    free(ptr);
    return 0;
}
