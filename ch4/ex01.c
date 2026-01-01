#include <assert.h>
#include <stdio.h>

int strrindex(char[], char[]);

int main(int argc, char *argv[])
{
    int i;

    i = strrindex(argv[1], argv[2]);
    printf("%d\n", i);

    return 0;
}

int strrindex(char haystack[], char needle[])
{
    int i, j, m, n;

    for (m = 0; haystack[m] != '\0'; m++);
    for (n = 0; needle[n] != '\0'; n++);

    for (i = m - n; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}
