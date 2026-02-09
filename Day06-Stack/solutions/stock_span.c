/*
Overview:
- Computes stock span for each day.
Approach:
- Use a stack of indices for previous greater price.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} IntStack;

void init_stack(IntStack *s) {
    s->top = -1;
}

int is_empty(const IntStack *s) {
    return s->top == -1;
}

void push(IntStack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(IntStack *s) {
    return s->data[(s->top)--];
}

int peek(const IntStack *s) {
    return s->data[s->top];
}

void stock_span(const int price[], int n, int span[]) {
    IntStack s;
    init_stack(&s);

    push(&s, 0);
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (!is_empty(&s) && price[peek(&s)] <= price[i]) {
            pop(&s);
        }
        span[i] = is_empty(&s) ? (i + 1) : (i - peek(&s));
        push(&s, i);
    }
}

int main(void) {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = (int)(sizeof(price) / sizeof(price[0]));
    int span[7];

    stock_span(price, n, span);
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("\n");
    return 0;
}
