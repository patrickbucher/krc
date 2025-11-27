#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char *argv[])
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    len = 0;
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        if (max >= MAXLINE) {
            printf("%s[...]", longest);
        } else {
            printf("%s", longest);
        }
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i, j;

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++j) {
        if (i < lim - 1) {
            s[i++] = c;
        }
    }
    if (c == '\n' && i < lim - 1) {
        s[i++] = c;
    }
    s[i] = '\0';

    return j;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
