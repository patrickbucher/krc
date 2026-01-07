#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 1024
#define N_VARS 27               /* a-z and _ */

double stack[STACK_SIZE];
double vars[N_VARS];
int sp = 0;

void push(double);
double pop(void);
double tip(void);
void clear(void);
void set_var(char, double);
double get_var(char);
int is_var_name(char);

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
                fprintf(stderr, "divide by zero\n");
                exit(1);
            }
            push(l / r);
        } else if (strcmp(argv[i], "%") == 0) {
            r = pop();
            l = pop();
            if (r == 0.0) {
                fprintf(stderr, "modulo by zero\n");
                exit(1);
            } else if (l < 0 || l < 0) {
                fprintf(stderr,
                        "modulo only allowed for positive numbers\n");
                exit(1);
            }
            push((double) ((int) l % (int) r));
        } else if (strcmp(argv[i], "print") == 0) {
            printf("%.3f ", tip());
            set_var('_', tip());
        } else if (strcmp(argv[i], "dup") == 0) {
            push(tip());
        } else if (strcmp(argv[i], "swap") == 0) {
            r = pop();
            l = pop();
            push(r);
            push(l);
        } else if (strcmp(argv[i], "clear") == 0) {
            clear();
        } else if (strcmp(argv[i], "sin") == 0) {
            push(sin(pop()));
        } else if (strcmp(argv[i], "cos") == 0) {
            push(cos(pop()));
        } else if (strcmp(argv[i], "exp") == 0) {
            push(exp(pop()));
        } else if (strcmp(argv[i], "pow") == 0) {
            r = pop();
            l = pop();
            push(pow(l, r));
        } else if (argv[i][0] == 'w' && is_var_name(argv[i][1])) {
            set_var(argv[i][1], pop());
        } else if (argv[i][0] == 'r' && is_var_name(argv[i][1])) {
            push(get_var(argv[i][1]));
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
    fprintf(stderr, "pop on empty stack\n");
    exit(1);
}

double tip(void)
{
    if (sp) {
        return stack[sp - 1];
    }
    fprintf(stderr, "tip of empty stack\n");
    exit(1);
}

void clear(void)
{
    sp = 0;
}

void set_var(char var, double val)
{
    if (var == '_') {
        vars[N_VARS - 1] = val;
    } else if (islower(var)) {
        vars[var - 'a'] = val;
    } else {
        fprintf(stderr, "illegal variable name '%c'\n", var);
        exit(1);
    }
}

double get_var(char var)
{
    if (var == '_') {
        return vars[N_VARS - 1];
    } else if (islower(var)) {
        return vars[var - 'a'];
    } else {
        fprintf(stderr, "illegal variable name '%c'\n", var);
        exit(1);
    }
}

int is_var_name(char c)
{
    return islower(c) || c == '_';
}
