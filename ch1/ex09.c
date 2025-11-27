#include <stdio.h>

int main(void)
{
    char c;
    int nb = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (nb == 0) {
                putchar(' ');
            }
            nb++;
        } else {
            putchar(c);
            nb = 0;
        }
    }

    return 0;
}
