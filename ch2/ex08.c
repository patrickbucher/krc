#include <stdio.h>
#include <stdlib.h>

unsigned int rightrot(unsigned int, unsigned int);

int main(int argc, char *argv[])
{
    unsigned int x, n, y;

    x = atoi(argv[1]);
    n = atoi(argv[2]);
    y = rightrot(x, n);
    printf("%d\n", y);

    return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    return x >> n;
}
