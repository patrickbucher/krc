#include <stdbool.h>
#include <stdio.h>

// The program's behaviour with single line inputs is questionable.
//
// $ echo -n 'This is a test' | ./ex11
// 0 4 14

int main(void)
{
    _Bool in = false;
    char c = 0;
    int nc = 0, nw = 0, nl = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            in = false;
        } else if (!in) {
            in = true;
            nw++;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
