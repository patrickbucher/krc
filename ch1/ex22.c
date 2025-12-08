#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 36

bool is_blank(char);
int find_last_non_blank(char[], int);
int find_last_blank(char[], int);
int shift_left(char[], int);

int main(void)
{
    char line[LINE_LENGTH + 1], c;
    int last_blank_at = -1, last_non_blank_at = -1, i = 0;

    while ((c = getchar()) != EOF) {
        if (i < LINE_LENGTH) {
            line[i++] = c;
        } else if (last_blank_at != -1) {
            last_non_blank_at = find_last_non_blank(line, LINE_LENGTH);
            line[last_non_blank_at + 1] = '\0';
            puts(line);
            i = shift_left(line, last_non_blank_at);
            last_blank_at = find_last_blank(line, i);
            line[i++] = c;
        } else {
            line[LINE_LENGTH] = '\0';
            putchar('-');
            puts(line);
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

bool is_blank(char c)
{
    return c == ' ' || c == '\t';
}

int find_last_non_blank(char line[], int n)
{
    int last_non_blank = -1;
    for (int i = 0; i < n; i++) {
        if (!is_blank(line[i]) && line[i] != '\n' && line[i] != '\0') {
            last_non_blank = i;
        }
    }
    return last_non_blank;
}

int find_last_blank(char line[], int n)
{
    int last_blank = -1;
    for (int i = 0; i < n; i++) {
        if (is_blank(line[i])) {
            last_blank = i;
        }
    }
    return last_blank;
}

int shift_left(char line[], int i)
{
    int r, w;
    for (r = i, w = 0; line[r] != '\0'; r++, w++) {
        line[w] = line[r];
    }
    line[w] = '\0';
    return w - 1;
}
