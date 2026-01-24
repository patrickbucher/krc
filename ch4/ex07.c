#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char[]);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    char c;

    while ((c = getch()) != EOF) {
        if (isalnum(c) || isspace(c)) {
            printf("%c", c);
        } else if (c == '.') {
            ungets("FULLSTOP");
        }
    }

    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        fprintf(stderr, "ungetch: too many characters\n");
        exit(1);
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[])
{
    int i, n;

    for (i = 0; s[i] != '\0'; i++);
    n = i;

    for (i = n - 1; i >= 0; i--) {
        ungetch(s[i]);
    }
}
