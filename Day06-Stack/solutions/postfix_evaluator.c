/*
Overview:
- Evaluates a postfix expression with single-digit operands.
Approach:
- Use a stack; push numbers and apply operators.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} IntStack;

void init_stack(IntStack *s) {
    s->top = -1;
}

void push(IntStack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(IntStack *s) {
    return s->data[(s->top)--];
}

int evaluate_postfix(const char *expr) {
    IntStack s;
    init_stack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isspace((unsigned char)c)) {
            continue;
        }
        if (isdigit((unsigned char)c)) {
            push(&s, c - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (c) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
    }

    return pop(&s);
}

int main(void) {
    const char *expr = "23+5*";
    printf("Result = %d\n", evaluate_postfix(expr));
    return 0;
}
