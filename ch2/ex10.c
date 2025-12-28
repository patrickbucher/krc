#include <stdio.h>
#include <string.h>

char lower(char);

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < strlen(argv[1]); i++) {
        printf("%c", lower(argv[1][i]));
    }
    putchar('\n');

    return 0;
}

char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
