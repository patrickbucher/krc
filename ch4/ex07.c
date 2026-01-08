#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getop(char[]);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
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

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c; /* not a number */
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())); /* collect integer part */
        if (c == '.') {
            while (isdigit(s[++i] = c = getch())); /* collect fraction part */
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return number;
}
