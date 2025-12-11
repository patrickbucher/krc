#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 12

int main(void)
{
    char line[LINE_LENGTH + 1]; // 0-terminated
    char c;
    int i = 0, j = 0, r = 0, w = 0, bp = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[i] = '\0';
            puts(line);
            i = 0;
        } else if (c == ' ') {
            if (i < LINE_LENGTH) {
                line[i] = c;
                if (i > 0 && line[i - 1] != ' ') {
                    bp = i;
                }
                i++;
            } else {
                line[i] = '\0';
                puts(line);
                i = 0;
            }
        } else if (i < LINE_LENGTH) {
            line[i++] = c;
            line[i] = '\0';
        } else {
            for (j = 0; j < bp; j++) {
                putchar(line[j]);
            }
            putchar('\n');
            for (r = bp + 1, w = 0; line[r] != '\0' && r < i;) {
                line[w++] = line[r++];
            }
            line[w++] = c;
            line[w] = '\0';
            i = w;
        }
    }

    return 0;
}
