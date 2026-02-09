/*
Overview:
- Implements a fixed-size stack using an array.
Approach:
- Maintain a top index for push/pop.
Complexity:
- Time: O(1) per operation
- Space: O(n)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

bool is_empty(const Stack *s) {
    return s->top == -1;
}

bool is_full(const Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int main(void) {
    Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    return 0;
}
