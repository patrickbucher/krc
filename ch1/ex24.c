#include <stdio.h>

#define STACK_SIZE 32

char counterpart(char);

/* limited syntax check: only checks for balances {}, [], (), and "". */
int main(void)
{
    char c, c1 = 0, stack[STACK_SIZE];
    int s = 0, line = 1, col = 1;

    while ((c = getchar()) != EOF) {
        switch (c) {
        case '"':
        case '\'':
            if (stack[s - 1] == c && c1 != '\\') {
                s--;
            } else if (c1 != '\\') {
                stack[s++] = c;
            }
            break;
        case '{':
        case '[':
        case '(':
            if (stack[s - 1] == '"' || stack[s - 1] == '\'') {
                break;
            }
            stack[s++] = c;
            break;
        case '}':
        case ']':
        case ')':
            if (stack[s - 1] == '"' || stack[s - 1] == '\'') {
                break;
            }
            if (stack[s - 1] == counterpart(c) && s >= 0) {
                s--;
            } else {
                printf
                    ("%c instead of %c to close %c on line %d, column %d\n",
                     c, counterpart(c), stack[s - 1], line, col);
                return 1;
            }
            break;
        case '\n':
            line++;
            col = 1;
            break;
        default:
            col++;
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
