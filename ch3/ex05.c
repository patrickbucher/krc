#include <stdio.h>
#include <stdlib.h>

void itob(int, char[], int);
void reverse(char[]);

int main(int argc, char *argv[])
{
    int n, b;
    char buf[256];

    n = atoi(argv[1]);
    b = atoi(argv[2]);
    itob(n, buf, b);
    printf("%s\n", buf);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, p;

    i = 0;
    do {
        p = n % b;
        p = p <= 9 ? p + '0' : p - 10 + 'a';
        s[i++] = p;
    } while ((n /= b) > 0);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, n;
    char c;

    for (n = 0; s[n] != '\0'; n++);
    for (i = 0; i < n / 2; i++) {
        c = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = c;
    }
    s[n] = '\0';
}
