#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024
#define BUFSIZE 100
#define MAXOP 100
#define NUMBER 0

int getline(char[], int);
int getop(char[]);
void push(double);
double pop(void);

double stack[STACK_SIZE];
int sp = 0;
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;               /* not a number */
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));  /* collect integer part */
        if (c == '.') {
            while (isdigit(s[++i] = c = getch()));      /* collect fraction part */
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
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
