#include <stdio.h>
#include <stdlib.h>

unsigned int setbits(unsigned int, unsigned int, unsigned int,
                     unsigned int);

int main(int argc, char *argv[])
{
    unsigned int x, p, n, y, z;

    x = atoi(argv[1]);
    p = atoi(argv[2]);
    n = atoi(argv[3]);
    y = atoi(argv[4]);
    z = setbits(x, p, n, y);
    printf("%d\n", z);

    return 0;
}

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n,
                     unsigned int y)
{
    unsigned int retain, left, right, mask;

    retain = x & ~(~0 << (p + 1 - n));
    left = (x >> (p + 1)) << n;
    right = ~(~0 << n) & y;
    mask = (left | right) << (p + 1 - n);

    return mask | retain;
}
