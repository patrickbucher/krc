#include <stdio.h>

int main(void)
{
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == ' ') {
            printf("\\b");
        } else if (c == '\n') {
            printf("\\n");
        } else {
            putchar(c);
        }
    }

    return 0;
}
