#include <stdio.h>
#include <stdlib.h>

unsigned int length(unsigned int);
unsigned int ones(unsigned int);
unsigned int invert(unsigned int, unsigned int, unsigned int);

int main(int argc, char *argv[])
{
    unsigned int x, p, n, y;

    x = atoi(argv[1]);
    p = atoi(argv[2]);
    n = atoi(argv[3]);
    y = invert(x, p, n);
    printf("%d\n", y);

    return 0;
}

unsigned int length(unsigned int x)
{
    unsigned int n;

    for (n = 0; x > 0; n++) {
        x >>= 1;
    }

    return n;
}

unsigned int ones(unsigned int n)
{
    return ~((~0 >> n) << n);
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    unsigned int shift, left, right, mask, state, inverted;

    shift = p - n + 1;
    left = (x >> (p + 1)) << (p + 1);
    right = x & ones(shift);

    mask = ones(n) << shift;
    state = x & mask;
    state = ~state & ones(p + 1);
    inverted = state & mask;

    return left | inverted | right;
}
