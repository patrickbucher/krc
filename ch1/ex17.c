#include <stdio.h>

#define TRESHOLD 80
#define BUFFERING 1
#define PRINTING 2

int main(void)
{
    char c, buf[TRESHOLD + 1];
    int mode = BUFFERING, i = 0;

    while ((c = getchar()) != EOF) {
        if (i < TRESHOLD) {
            buf[i++] = c;
        } else if (mode == BUFFERING) {
            mode = PRINTING;
            buf[TRESHOLD] = '\0';
            printf("%s", buf);
        }
        if (mode == PRINTING) {
            putchar(c);
        }
        if (c == '\n') {
            i = 0;
            mode = BUFFERING;
        }
    }

    return 0;
}
