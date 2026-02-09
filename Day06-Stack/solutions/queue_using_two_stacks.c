/*
Overview:
- Implements a queue using two stacks.
Approach:
- Push to stack_in; pop from stack_out, refilling when needed.
Complexity:
- Amortized Time: O(1)
- Space: O(n)
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} IntStack;

typedef struct {
    IntStack in;
    IntStack out;
} Queue;

void init_stack(IntStack *s) {
    s->top = -1;
}

int is_empty_stack(const IntStack *s) {
    return s->top == -1;
}

void push_stack(IntStack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop_stack(IntStack *s) {
    return s->data[(s->top)--];
}

void init_queue(Queue *q) {
    init_stack(&q->in);
    init_stack(&q->out);
}

void enqueue(Queue *q, int value) {
    push_stack(&q->in, value);
}

int dequeue(Queue *q) {
    if (is_empty_stack(&q->out)) {
        while (!is_empty_stack(&q->in)) {
            push_stack(&q->out, pop_stack(&q->in));
        }
    }
    if (is_empty_stack(&q->out)) {
        return -1;
    }
    return pop_stack(&q->out);
}

int main(void) {
    Queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}
