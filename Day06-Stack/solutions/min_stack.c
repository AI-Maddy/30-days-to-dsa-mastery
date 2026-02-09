/*
Overview:
- Stack that supports getMin in O(1).
Approach:
- Maintain a parallel stack of minimums.
Complexity:
- Time: O(1) per operation
- Space: O(n)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int min_data[MAX];
    int top;
} MinStack;

void init_stack(MinStack *s) {
    s->top = -1;
}

bool is_empty(const MinStack *s) {
    return s->top == -1;
}

bool is_full(const MinStack *s) {
    return s->top == MAX - 1;
}

void push(MinStack *s, int value) {
    if (is_full(s)) {
        return;
    }
    s->data[++(s->top)] = value;
    if (s->top == 0) {
        s->min_data[s->top] = value;
    } else {
        int current_min = s->min_data[s->top - 1];
        s->min_data[s->top] = (value < current_min) ? value : current_min;
    }
}

int pop(MinStack *s) {
    if (is_empty(s)) {
        return -1;
    }
    return s->data[(s->top)--];
}

int get_min(const MinStack *s) {
    if (is_empty(s)) {
        return -1;
    }
    return s->min_data[s->top];
}

int main(void) {
    MinStack s;
    init_stack(&s);

    push(&s, 5);
    push(&s, 2);
    push(&s, 8);

    printf("Min = %d\n", get_min(&s));
    pop(&s);
    printf("Min = %d\n", get_min(&s));
    return 0;
}
