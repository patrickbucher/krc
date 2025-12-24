#include <stdio.h>

int any(char[], char[]);

int main(int argc, char *argv[])
{
    int p;

    p = any(argv[1], argv[2]);
    printf("any(%s, %s) = %d\n", argv[1], argv[2], p);

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return 1;
}
