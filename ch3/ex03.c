#include <stdio.h>
#include <ctype.h>

void expand(char[], char[]);

int main(int argc, char *argv[])
{
    char buf[1024];

    expand(argv[1], buf);
    printf("%s\n", buf);

    return 0;
}

void expand(char s1[], char s2[])
{
    char first, last, c;
    int r, w;

    first = 0, last = 0;
    r = s1[0] == '-' ? 1 : 0;
    for (w = 0; (c = s1[r]) != '\0'; r++) {
        if (isalnum(c)) {
            if (first && s1[r - 1] == '-') {
                last = c;
            } else if (isalnum(s1[r - 1])) {
                first = c;
                last = 0;
            }
        } else if (c == '-') {
            if (isalnum(s1[r - 1])) {
                if (s1[r - 1] == last) {
                    first = s1[r - 1] + 1;
                } else {
                    first = s1[r - 1];
                }
                last = 0;
            }
        }
        if (first && last && first < last) {
            for (c = first; c <= last; c++) {
                s2[w++] = c;
            }
        }
    }
    s2[w] = '\0';
}
