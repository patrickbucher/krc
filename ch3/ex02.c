#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int escape(char[], char[]);
int unescape(char[], char[]);

int main(int argc, char *argv[])
{
    int n;
    char *copy;

    n = strlen(argv[2]);
    copy = malloc(sizeof(char) * n * 2 + 1);

    if (strcmp(argv[1], "escape") == 0) {
        escape(argv[2], copy);
        printf("%s", copy);
    } else if (strcmp(argv[1], "unescape") == 0) {
        unescape(argv[2], copy);
        printf("%s", copy);
    }

    return 0;
}

int escape(char s[], char t[])
{
    int r, w;

    for (r = 0, w = 0; s[r] != '\0'; r++) {
        switch (s[r]) {
        case '\t':
            t[w++] = '\\';
            t[w++] = 't';
            break;
        case '\n':
            t[w++] = '\\';
            t[w++] = 'n';
            break;
        default:
            t[w++] = s[r];
            break;
        }
    }
    t[w] = '\0';

    return w;
}

int unescape(char s[], char t[])
{
    int r, w, escaped;

    escaped = 0;
    for (r = 0, w = 0; s[r] != '\0'; r++) {
        switch (s[r]) {
        case 't':
            if (escaped) {
                t[w++] = '\t';
            } else {
                t[w++] = s[r];
            }
            escaped = 0;
            break;
        case 'n':
            if (escaped) {
                t[w++] = '\n';
            } else {
                t[w++] = s[r];
            }
            escaped = 0;
            break;
        case '\\':
            escaped = 1;
            break;
        default:
            if (escaped) {
                t[w++] = '\\';
            }
            t[w++] = s[r];
            escaped = 0;
        }
    }
    t[w] = '\0';

    return w;
}
