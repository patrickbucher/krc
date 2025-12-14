#include <stdio.h>

#define BUFSIZE 2

/* This program removes comments from code.
   The code is heavily commented to double as test data. */
int main(void)
{
    char c, buf[BUFSIZE] /* lookback buffer */ ;
    int b = 0, in_comment = 0, i;

    while ((c = getchar()) != EOF) {
        /* shift buffer to the left */
        for (i = 0; i < BUFSIZE; i++) {
            buf[i] = buf[i + 1];
            b = i;
        }
        buf[b] = c;
        if (in_comment && buf[b - 1] == '*' && buf[b] == '/') {
            in_comment = 0;
        } else if (buf[b - 1] == '/' && buf[b] == '*') {
            in_comment = 1;
        }
        if (!in_comment && b > 0 && buf[b - 1] != '*' && buf[b - 1] != '/') {
            putchar(buf[b - 1]);
        }
    }
    putchar(buf[b]);            /* flush the remainder */

    return 0;
}
