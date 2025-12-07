#include <stdio.h>

#define TAB_AT 4

int main(void)
{
    char c;
    int pos;

    pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            pos = 0;
            putchar(c);
        } else if (c == '\t') {
            while (pos == 0 || pos % TAB_AT != 0) {
                putchar(' ');
                pos++;
            }
        } else {
            putchar(c);
            pos++;
        }
    }

    return 0;
}
