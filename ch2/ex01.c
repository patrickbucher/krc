#include <float.h>
#include <limits.h>
#include <stdio.h>

unsigned long upow(int, int);
double fpow(float, float);

int main(void)
{
    size_t char_bytes, short_bytes, int_bytes, long_bytes;
    size_t char_bits, short_bits, int_bits, long_bits;

    /* integer constants */
    printf("signed char:\t[%d,%d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:\t[%d,%u]\n", 0, UCHAR_MAX);
    printf("signed short:\t[%d,%d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:\t[%d,%u]\n", 0, USHRT_MAX);
    printf("signed int:\t[%d,%d]\n", INT_MIN, INT_MAX);
    printf("unsigned int:\t[%d,%u]\n", 0, UINT_MAX);
    printf("signed long:\t[%ld,%ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:\t[%d,%lu]\n", 0, ULONG_MAX);

    /* integer calculations */
    char_bytes = sizeof(char);
    short_bytes = sizeof(short);
    int_bytes = sizeof(int);
    long_bytes = sizeof(long);
    char_bits = char_bytes * 8 - 1;
    short_bits = short_bytes * 8 - 1;
    int_bits = int_bytes * 8 - 1;
    long_bits = long_bytes * 8 - 1;

    printf("signed char:\t[%d,%d]\n",
           (char) -(upow(2, char_bits)), (char) upow(2, char_bits) - 1);
    printf("unsigned char:\t[%d,%u]\n", 0,
           (unsigned char) upow(2, char_bits + 1) - 1);
    printf("signed short:\t[%d,%d]\n", (short) -(upow(2, short_bits)),
           (short) upow(2, short_bits) - 1);
    printf("unsigned short:\t[%d,%u]\n", 0,
           (unsigned short) upow(2, short_bits + 1) - 1);
    printf("signed int:\t[%d,%d]\n", (int) -(upow(2, int_bits)),
           (int) upow(2, int_bits) - 1);
    printf("unsigned int:\t[%d,%u]\n", 0, 0 - 1);
    printf("signed long:\t[%ld,%ld]\n",
           (long) -(upow(2, long_bits)), (long) upow(2, long_bits) - 1);
    printf("unsigned long:\t[%d,%lu]\n", 0, (unsigned long) 0 - 1);

    /* floating point constants */
    printf("float:\t\t[%g,%g]\n", FLT_MIN, FLT_MAX);
    printf("double:\t\t[%g,%g]\n", DBL_MIN, DBL_MAX);

    /* floating point calculations */
    /* FIXME: overflow */
    printf("float:\t\t[%g,%g]\n", -fpow(FLT_RADIX, FLT_MAX_EXP),
           fpow(FLT_RADIX, FLT_MAX_EXP));
    /* FIXME: underflow, overflow */
    printf("double:\t\t[%g,%g]\n", -fpow(FLT_RADIX, DBL_MAX_EXP),
           fpow(FLT_RADIX, DBL_MAX_EXP));

    return 0;
}

unsigned long upow(int b, int e)
{
    int i;
    unsigned long x = b;
    for (i = 1; i < e; i++) {
        x *= b;
    }
    return x;
}

double fpow(float b, float e)
{
    int i;
    double x = b;
    for (i = 1; i < e; i++) {
        x *= b;
    }
    return x;
}
