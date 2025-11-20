#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;
    while (1) {
        printf("getchar != EOF? %d\n", (c = getchar()) != EOF);
        if (c == EOF) {
            break;
        }
    }
    return 0;
}
