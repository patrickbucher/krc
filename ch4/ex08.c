#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int getch(void);
void ungetch(int);

char buf;

int main(void)
{
    char c;

    buf = '\0';
    while ((c = getch()) != EOF) {
        if (c == '.') {
            ungetch('-');
        } else {
            printf("%c", c);
        }
    }

    return 0;
}

int getch(void)
{
    char c;

    if (buf == '\0') {
        return getchar();
    } else {
        c = buf;
        buf = '\0';
        return c;
    }
}

void ungetch(int c)
{
    buf = c;
}
