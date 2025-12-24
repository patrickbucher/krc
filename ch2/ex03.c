#include <ctype.h>
#include <stdio.h>
#include <string.h>

long htoi(char[]);

int main(int argc, char *argv[])
{
    long decimal;

    decimal = htoi(argv[1]);
    printf("%ld\n", decimal);

    return 0;
}

long htoi(char h[])
{
    int i, d, l;
    char c;

    l = strlen(h);
    i = (l >= 1 && h[0] == '0' && (h[1] == 'x' || h[1] == 'X')) ? 2 : 0;

    for (d = 0; i < l; i++) {
        c = h[i];
        if (isdigit(c)) {
            d = 16 * d + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            d = 16 * d + c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            d = 16 * d + c - 'A' + 10;
        }
    }

    return d;
}
