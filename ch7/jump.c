#include <stdio.h>
#include <setjmp.h>
static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main(int argc, char* argv[])
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;

    globval = 1;
    autoval = 1;
    regival = 1;
    volaval = 1;
    statval = 1;

    if (setjmp(jmpbuffer) != 0) {
        printf("after long jump: \n");
        printf("globval = %d, autoval = %d, regival = %d,"
                " volaval = %d, statval = %d\n",
                globval, autoval, regival, volaval, statval);
        exit(0);
    }

    globval = 95; autoval = 96; regival = 97; volaval = 98; statval = 99;
    f1(autoval, regival, volaval, statval);
    exit(0);
}
static void
f1(int i, int j, int k, int l)
{
    printf("int f1():\n");
    printf("globval = %d, autoval = %d, regival = %d"
            " volaval = %d, statval = %d\n", globval, i, j, k,l);
    f2();
}

static void
f2(void)
{
    longjmp(jmpbuffer, 1);
}


