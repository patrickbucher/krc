#include <stdio.h>
#include <stdlib.h>

unsigned int bitcount(unsigned int);
unsigned int fast_bitcount(unsigned int);

int main(int argc, char *argv[])
{
    unsigned int n, b;

    n = atoi(argv[1]);

    b = bitcount(n);
    printf("%d\n", b);

    b = fast_bitcount(n);
    printf("%d\n", b);

    return 0;
}

unsigned int bitcount(unsigned int x)
{
    unsigned int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }

    return b;
}

/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why.
 * x is either odd or even, i.e. the rightmost bit is either 1 or 0, respectively.
 * If the rightmost bit is 1, x-1 will turn it into 0, and x &= (x-1) will get rid of that bit.
 * If the rightmost bit is 0, x-1 will turn it into 1, but also change the rightmost 1 bit:
 * 10 - 1 = 01, 10 &= 01 = 0
 * 110 - 1 = 101, 110 &= 101 = 100
 * 1000 - 1 = 0111, 1000 &= 0111 = 0
 * 1110 - 1 = 1101, 1110 &= 1101 = 1100
 * All bits of the right of the rightmost 1-bit are switched.
 */

unsigned int fast_bitcount(unsigned int x)
{
    unsigned int b;

    for (b = 0; x != 0; b++) {
        x &= (x - 1);
    }

    return b;
}
