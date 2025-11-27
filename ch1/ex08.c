#include <stdio.h>

int main(void)
{
    int blanks = 0, tabs = 0, newlines = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            newlines++;
        }
    }
    printf("blanks:   %8d\n", blanks);
    printf("tabs:     %8d\n", tabs);
    printf("newlines: %8d\n", newlines);

    return 0;
}
