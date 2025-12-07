#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 36

bool is_blank(char c)
{
    return c == ' ' || c == '\t';
}

int main(void)
{
    char line[LINE_LENGTH + 1], c;
    int last_blank_at = -1, last_non_blank_at = -1, i = 0;

    while ((c = getchar()) != EOF) {
        if (i < LINE_LENGTH) {
            line[i++] = c;
        } else if (last_blank_at != -1) {
            for (int j = last_blank_at; j >= 0; j--) {
                if (line[j] != '\t' && line[j] != ' ') {
                    last_non_blank_at = j;
                    break;
                }
            }
            line[last_non_blank_at + 1] = '\0';
            puts(line);
            for (int r = last_non_blank_at + 1, w = 0; r < i; r++) {
                line[w++] = line[r++];
                i = w;
                if (is_blank(line[i])) {
                    last_blank_at = i;
                }
            }
            i = 0;
        } else {
            line[LINE_LENGTH] = '\0';
            puts(line);
            c = '\n';
            i = 0;
        }
        if (c == '\n') {
            line[i] = '\0';
            puts(line);
            for (int j = i; j >= 0; j--) {
                line[j] = '\0';
            }
            i = 0;
            last_blank_at = -1;
        } else if (is_blank(c)) {
            last_blank_at = i;
        }
    }
    puts(line);

    return 0;
}
