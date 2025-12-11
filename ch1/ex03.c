#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int lower, upper, step;
    float fahr, cel;

    if (argc != 4) {
        fprintf(stderr, "usage: %s LOWER UPPER STEP\n", argv[0]);
        return 1;
    }

    lower = atoi(argv[1]);
    upper = atoi(argv[2]);
    step = atoi(argv[3]);

    if (lower >= upper) {
        fprintf(stderr, "upper must be greater than lower");
        return 1;
    }
    if (step <= 0) {
        fprintf(stderr, "step must be positive");
        return 1;
    }

    printf("%6s\t%6s\n", "F", "C");
    while (lower <= upper) {
        fahr = (float) lower;
        cel = 5 * (fahr - 32) / 9;
        printf("%6.2f\t%6.2f\n", fahr, cel);
        lower += step;
    }

    return 0;
}
