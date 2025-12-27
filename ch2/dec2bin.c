#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *dec2bin(unsigned int);

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s\n", dec2bin(atoi(argv[i])));
    }

    return 0;
}

char *dec2bin(unsigned int dec)
{
    int i, n;
    char c, *bin;

    if (dec == 0) {
        bin = malloc(sizeof(char) * 2);
        bin[0] = '0';
        bin[1] = '\0';
        return bin;
    }

    n = (int) (log2(dec) + 1);
    bin = malloc(sizeof(char) * (n + 1));
    bin[n] = '\0';

    for (i = 0; i < n; i++) {
        c = dec % 2 + '0';
        dec /= 2;
        bin[n - i - 1] = c;
    }

    return bin;
}
