#include <stdio.h>

#define LINE_LIMIT 72

int readline(char[], int);

int main(void)
{
    char s[LINE_LIMIT];

    readline(s, LINE_LIMIT);
    printf("%s\n", s);

    return 0;
}

int readline(char s[], int lim)
{
    int i;
    char c;

    for (i = 0; (c = getchar()) != '\n'; i++) {
        if (c == EOF) {
            break;
        }
        if (i >= lim - 1) {
            break;
        }
        s[i] = c;
    }
    s[i] = '\0';

    return i;
}
