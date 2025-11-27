#include <stdio.h>

#define UPPER_COUNT ('Z' - 'A' + 1)
#define LOWER_COUNT ('z' - 'a' + 1)
#define DIGIT_COUNT ('9' - '0' + 1)
#define TOTAL_COUNT (UPPER_COUNT + LOWER_COUNT + DIGIT_COUNT)

#define UPPER_OFFSET 0
#define LOWER_OFFSET (UPPER_OFFSET + UPPER_COUNT)
#define DIGIT_OFFSET (LOWER_OFFSET + LOWER_COUNT)

int main(void)
{
    int counts[TOTAL_COUNT];
    char c;

    for (int i = 0; i < TOTAL_COUNT; i++) {
        counts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            counts[c - 'a' + LOWER_OFFSET]++;
        } else if (c >= '0' && c <= '9') {
            counts[c - '0' + DIGIT_OFFSET]++;
        }
    }

    for (int i = UPPER_OFFSET; i < LOWER_OFFSET; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < counts[i]; j++) {
            putchar('=');
        }
        putchar('\n');
    }
    for (int i = LOWER_OFFSET; i < DIGIT_OFFSET; i++) {
        printf("%c ", i - LOWER_OFFSET + 'a');
        for (int j = 0; j < counts[i]; j++) {
            putchar('=');
        }
        putchar('\n');
    }
    for (int i = DIGIT_OFFSET; i < TOTAL_COUNT; i++) {
        printf("%c ", i - DIGIT_OFFSET + '0');
        for (int j = 0; j < counts[i]; j++) {
            putchar('=');
        }
        putchar('\n');
    }

    return 0;
}
