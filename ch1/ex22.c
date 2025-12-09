#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 24

int main(void)
{
    char line[LINE_LENGTH + 1]; // 0-terminated
    char c;
    int i = 0, bp = 0;

    while ((c = getchar()) != EOF) {
        if (i < LINE_LENGTH) {
            line[i] = c;
        } else {
            line[bp] = '\0';
            puts(line);
            i = -1;
        }
        if (i > 1 && c == ' ' && line[i - 1] != ' ') {
            bp = i;
        }
        i++;
    }

    return 0;
}
