#include <stdio.h>

#define STACK_SIZE 32

char counterpart(char);

/* limited syntax check: only checks for balanced {}, [], (), and "". */
int main(void)
{
    char c, c1 = 0, stack[STACK_SIZE];
    int s = 0, line = 1, col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line++;
            col = 0;
        } else {
            col++;
        }
        switch (c) {
        case '"':
        case '\'':
            if (stack[s - 1] == c && c1 != '\\') {
                stack[s--] = '\0';
            } else if (c1 != '\\') {
                stack[s++] = c;
            }
            break;
        case '{':
        case '[':
        case '(':
            if (stack[s - 1] != '"' && stack[s - 1] != '\'') {
                stack[s++] = c;
            }
            break;
        case '}':
        case ']':
        case ')':
            if (stack[s - 1] == '"' || stack[s - 1] == '\'') {
                break;
            }
            if (stack[s - 1] == counterpart(c) && s >= 0) {
                stack[s--] = '\0';
            } else {
                printf("%d,%d %c instead of %c to close %c\n",
                       line, col, c, counterpart(stack[s - 1]),
                       stack[s - 1]);
                stack[s] = '\0';
                puts(stack);
                return 1;
            }
            break;
        }
        c1 = c;
    }
    if (s > 0) {
        for (; s > 0; s--) {
            printf("%c remains unclosed\n", stack[s - 1]);
        }
        return 1;
    }

    return 0;
}

char counterpart(char c)
{
    switch (c) {
    case '}':
        return '{';
    case ']':
        return '[';
    case ')':
        return '(';
    default:
        return 0;
    }
}
