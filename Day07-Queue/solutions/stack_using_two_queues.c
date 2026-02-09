/*
Overview:
- Implements a stack using two queues.
Approach:
- For push, enqueue to the empty queue and move all items behind it.
Complexity:
- Time: O(n) for push, O(1) for pop
- Space: O(n)
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int is_empty(const Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

typedef struct {
    Queue q1;
    Queue q2;
} Stack;

void init_stack(Stack *s) {
    init_queue(&s->q1);
    init_queue(&s->q2);
}

void push(Stack *s, int value) {
    Queue *active = is_empty(&s->q1) ? &s->q2 : &s->q1;
    Queue *buffer = is_empty(&s->q1) ? &s->q1 : &s->q2;

    enqueue(buffer, value);
    while (!is_empty(active)) {
        enqueue(buffer, dequeue(active));
    }

    /* Swap active and buffer by copying struct values. */
    Queue temp = *active;
    *active = *buffer;
    *buffer = temp;
}

int pop(Stack *s) {
    Queue *active = is_empty(&s->q1) ? &s->q2 : &s->q1;
    if (is_empty(active)) {
        return -1;
    }
    return dequeue(active);
}

int main(void) {
    Stack s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    return 0;
}
