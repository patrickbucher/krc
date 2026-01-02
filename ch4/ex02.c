#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atod(char[]);

int main(int argc, char *argv[])
{
    double d = atod(argv[1]);
    printf("%.6f\n", d);

    return 0;
}

double atod(char s[])
{
    double d;
    int i, sign, power, e, esign;

    for (i = 0; isspace(s[i]); i++);
    if (s[i] == '-') {
        i++;
        sign = -1;
    } else {
        sign = 1;
    }
    for (; isdigit(s[i]); i++) {
        d = d * 10 + s[i] - '0';
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1; isdigit(s[i]); i++) {
        d = d * 10 + s[i] - '0';
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }
    if (s[i] == '-') {
        i++;
        esign = -1;
    } else {
        esign = 1;
    }
    printf("dbg %c\n", s[i]);
    for (e = 1; isdigit(s[i]); i++) {
        e = e * 10 + s[i] - '0';
    }
    printf("e=%d, es=%d\n", e, esign);

    d = sign * d / power;
    if (e) {
        d = d * pow(10, e * esign);
    }
    return d;
}
