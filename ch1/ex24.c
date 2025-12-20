#include <assert.h>
#include <stdio.h>

#define STACK_SIZE 32

char counterpart(char);

/* limited syntax check: only checks for balanced {}, [], (), and "". */
int main(void)
{
    char c = 0, pp = 0, p = 0, tip = 0, stack[STACK_SIZE];
    int s = 0, i = 0, line = 1, col = 0, escaped = 0;

    stack[0] = '\0';
    while ((c = getchar()) != EOF) {
        assert(s >= 0);
        tip = s > 0 ? stack[s - 1] : 0;
        if (c == '\n') {
            line++;
            col = 0;
        } else {
            col++;
        }
        switch (c) {
        case '"':
            if (tip == c && p != '\\') {
                stack[s--] = '\0';
            } else if (p != '\'') {
                stack[s++] = c;
            }
            break;
        case '\'':
            escaped = p == '\\' && pp != '\\';
            if (tip == c && !escaped) {
                stack[s--] = '\0';
            } else if (tip && tip != '"' && !escaped) {
                stack[s++] = c;
            }
            break;
        case '{':
        case '[':
        case '(':
            if (tip != '"' && tip != '\'') {
                stack[s++] = c;
            }
            break;
        case '}':
        case ']':
        case ')':
            if (tip != '"' && tip != '\'') {
                if (tip == counterpart(c)) {
                    stack[s--] = '\0';
                } else {
                    printf("%d,%d %c instead of %c to close %c\n", line,
                           col, c, counterpart(tip), tip);
                    stack[s] = '\0';
                    puts(stack);
                    return 1;
                }
            }
            break;
        }
        pp = p;
        p = c;
    }

    for (i = s - 1; i >= 0; i--) {
        printf("%c remains unclosed\n", stack[i]);
    }
    if (s) {
        return -1;
    }

    return 0;
}

char counterpart(char c)
{
    switch (c) {
    case '{':
        return '}';
    case '[':
        return ']';
    case '(':
        return ')';
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
