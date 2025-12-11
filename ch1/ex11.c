#include <stdio.h>

int main(void)
{
    int in = 0;
    char c = 0;
    int nc = 0, nw = 0, nl = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            in = 0;
        } else if (!in) {
            in = 1;
            nw++;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
