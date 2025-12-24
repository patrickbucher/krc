#include <stdio.h>

void squeeze(char[], char[]);

int main(int argc, char *argv[])
{
    printf("squeeze(%s, %s) = ", argv[1], argv[2]);
    squeeze(argv[1], argv[2]);
    printf("%s\n", argv[1]);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int d, i, r, w, l1, l2;

    l1 = strlen(s1);
    l2 = strlen(s2);

    for (r = 0, w = 0; r < l1; r++) {
        d = 0;
        for (i = 0; i < l2; i++) {
            if (s2[i] == s1[r]) {
                d = 1;
                break;
            }
        }
        if (!d) {
            s1[w++] = s1[r];
        }
    }
    s1[w] = '\0';
}
