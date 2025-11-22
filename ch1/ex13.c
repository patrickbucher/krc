#include <stdio.h>

#define MAXLEN 20

int main(int argc, char *argv[])
{
    int hist[MAXLEN];
    char c = 0, n = 0;

    for (int i = 0; i < MAXLEN; i++) {
        hist[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (n > 0 && n <= MAXLEN) {
                hist[n - 1]++;
            }
            n = 0;
        } else {
            n++;
        }
    }

    for (int i = 0; i < MAXLEN; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < hist[i]; j++) {
            putchar('=');
        }
        putchar('\n');
    }

    return 0;
}
