#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

double stack[STACK_SIZE];
int sp = 0;

void push(double);
double pop(void);
double tip(void);
void clear(void);

int main(int argc, char *argv[])
{
    int i;
    double o, l, r;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "+") == 0) {
            push(pop() + pop());
        } else if (strcmp(argv[i], "-") == 0) {
            r = pop();
            l = pop();
            push(l - r);
        } else if (strcmp(argv[i], "*") == 0) {
            push(pop() * pop());
        } else if (strcmp(argv[i], "/") == 0) {
            r = pop();
            l = pop();
            if (r == 0.0) {
                fprintf(stderr, "divide by zero");
                exit(1);
            }
            push(l / r);
        } else if (strcmp(argv[i], "%") == 0) {
            r = pop();
            l = pop();
            if (r == 0.0) {
                fprintf(stderr, "modulo by zero");
                exit(1);
            } else if (l < 0 || l < 0) {
                fprintf(stderr,
                        "modulo only allowed for positive numbers");
                exit(1);
            }
            push((double) ((int) l % (int) r));
        } else if (strcmp(argv[i], "print") == 0) {
            printf("%.3f ", tip());
        } else if (strcmp(argv[i], "dup") == 0) {
            push(tip());
        } else if (strcmp(argv[i], "swap") == 0) {
            r = pop();
            l = pop();
            push(r);
            push(l);
        } else if (strcmp(argv[i], "clear") == 0) {
            clear();
        } else {
            o = atof(argv[i]);
            push(o);
        }
    }
    printf("%.3f\n", pop());

    return 0;
}

void push(double d)
{
    stack[sp++] = d;
}

double pop(void)
{
    if (sp) {
        return stack[--sp];
    }
    fprintf(stderr, "pop on empty stack");
    exit(1);
}

double tip(void)
{
    if (sp) {
        return stack[sp - 1];
    }
    fprintf(stderr, "tip of empty stack");
    exit(1);
}

void clear(void)
{
    sp = 0;
}
