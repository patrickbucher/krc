#include <stdio.h>

int main(int argc, char *argv[])
{
    char c = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }

    return 0;
}
