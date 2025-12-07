#include <stdio.h>

#define LINE_LENGTH 72

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
                if (line[i] == '\t' || line[i] == ' ') {
                    last_blank_at = i;
                }
            }
        } else {
            // TODO: hard break, implement later
        }
        if (c == '\n') {
            line[i] = '\0';
            puts(line);
            i = 0;
            last_blank_at = -1;
        } else if (c == '\t' || c == ' ') {
            last_blank_at = i;
        }
    }
    puts(line);

    return 0;
}
