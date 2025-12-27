#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    unsigned int shift, left, swap, right;

    shift = p - n + 1;
    left = x >> (p + 1) << (p + 1);
    swap = ((x >> shift) & ~(~0 << n));
    right = ~(~0 << shift) & x;

    return (left & ~swap) | right;
}

/* TODO: invert(x=1000'0001, p=5, n=4)
   1) create a mask of 1 bits of size n: 1111
   2) shift the mask to the left to fit p: 111100
   3) store the current bits using x & 111100 = 0000'0000
   4) invert those bits = 1111'1111
   5) get the new bits back using 1111'1111 & 111100 = 0011'1100
   6) or the left and right part: 1000'0000 | 0011'1100 | 0000'0001 = 10111101
*/
