#include <stdio.h>
#include <stdlib.h>

float fahr_to_cels(float);

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("usage: %s LOWER UPPER STEP\n", argv[0]);
        return 1;
    }

    float lower, upper, step;
    lower = atof(argv[1]);
    upper = atof(argv[2]);
    step = atof(argv[3]);
    if (lower > upper || step <= 0.0) {
        printf("usage: %s LOWER UPPER STEP\n", argv[0]);
        return 1;
    }

    printf("%10s\t%10s\n", "F", "C");
    for (float f = lower; f < upper; f += step) {
        float c = fahr_to_cels(f);
        printf("%10.2f\t%10.2f\n", f, c);
    }

    return 0;
}

float fahr_to_cels(float fahr)
{
    float cels = 5 * (fahr - 32) / 9;

    return cels;
}
