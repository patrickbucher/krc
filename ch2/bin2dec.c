#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin2dec(char[]);

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        printf("%d\n", bin2dec(argv[i]));
    }

    return 0;
}

int bin2dec(char bin[])
{
    int i, x;

    x = 0;
    for (i = 0; bin[i] != '\0'; i++) {
        switch (bin[i]) {
        case '0':
            x <<= 1;
            break;
        case '1':
            x = (x << 1) + 1;
            break;
        default:
            return -1;
        }
    }

    return x;
}
