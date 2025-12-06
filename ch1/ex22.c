#include <stdio.h>

#define LINE_LENGTH 72

int main(void)
{
    char line[LINE_LENGTH];
    int last_blank_at - 1, i = 0, c;

    while ((c = getchar()) != EOF) {
        line[i++] = c;
        if (c == '\n') {
            // TODO: flush
        } else if (c == '\t' || c == ' ') {
            last_blank_at = i;
        }
        if (w >= LINE_LENGTH) {
            // TODO output line[0..last_blank_at], conserve line[last_blank_at..i]
        }
    }

    return 0;
}
