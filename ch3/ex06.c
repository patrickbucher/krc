#include <stdio.h>
#include <stdlib.h>

void itos(int, char[], int);
void reverse(char[]);

int main(int argc, char *argv[])
{
    char buf[32];
    int x, w;

    x = atoi(argv[1]);
    w = atoi(argv[2]);
    itos(x, buf, w);
    printf("%s\n", buf);

    return 0;
}

void itos(int n, char s[], int w)
{
    int i, sign;
    long m = n;

    if ((sign = m) < 0) {
        m = -m;
    }
    i = 0;
    do {
        s[i++] = m % 10 + '0';
    } while ((m /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    while (i < w) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, n;
    char c;

    for (i = 0; s[i] != '\0'; i++);
    n = i;
    for (i = 0; i < n / 2; i++) {
        c = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = c;
    }
    s[n] = '\0';
}
