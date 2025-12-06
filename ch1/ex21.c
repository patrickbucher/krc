#include <stdio.h>

#define TAB_AT 4

int main(void)
{
    char c, blanks = 0, tabs, spaces, i;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            blanks += TAB_AT;
        } else if (c == '\n') {
            blanks = 0;
            putchar(c);
        } else if (blanks > 0) {
            tabs = blanks / TAB_AT;
            spaces = blanks % TAB_AT;
            for (i = 0; i < tabs; i++) {
                putchar('\t');
            }
            for (i = 0; i < spaces; i++) {
                putchar(' ');
            }
            blanks = 0;
            putchar(c);
        } else {
            putchar(c);
        }
    }
    return 0;
}
