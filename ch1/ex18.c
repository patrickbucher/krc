#include <stdio.h>

#define BUFSIZE 1024

int is_whitespace(char c)
{
    return c == ' ' || c == '\t';
}

int main(void)
{
    char c, buf[BUFSIZE];
    int i, j;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            for (j = i; j >= 0 && is_whitespace(buf[j]); j--) {
                buf[j] = '\0';
            }
            if (i > 0) {
                printf("%s\n", buf);
                i = 0;
                while (j >= 0) {
                    buf[j--] = '\0';
                }
            }
        } else {
            buf[i++] = c;
        }
    }

    return 0;
}
