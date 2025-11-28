#include <stdio.h>

#define BUFSIZE 1024

void reverse(char s[]);

int main(void)
{
    char c, buf[BUFSIZE];
    int i;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            reverse(buf);
            printf("%s\n", buf);
            i = 0;
        } else {
            buf[i++] = c;
            buf[i] = '\0';
        }
    }

    return 0;
}

void reverse(char s[])
{
    int n, i;
    char c;

    for (n = 0; s[n] != '\0'; n++);
    for (i = 0; i < n / 2; i++) {
        c = s[n - i - 1];
        s[n - i - 1] = s[i];
        s[i] = c;
    }
    s[n] = '\0';
}
