/*
Overview:
- Implements a circular array deque.
Approach:
- Track front, rear, and size with modulo arithmetic.
Complexity:
- Time: O(1) per operation
- Space: O(n)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 6

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init_deque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

bool is_empty(const Deque *dq) {
    return dq->size == 0;
}

bool is_full(const Deque *dq) {
    return dq->size == MAX;
}

void push_back(Deque *dq, int value) {
    if (is_full(dq)) {
        return;
    }
    dq->rear = (dq->rear + 1) % MAX;
    dq->data[dq->rear] = value;
    dq->size++;
}

void push_front(Deque *dq, int value) {
    if (is_full(dq)) {
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->data[dq->front] = value;
    dq->size++;
}

int pop_front(Deque *dq) {
    if (is_empty(dq)) {
        return -1;
    }
    int value = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    return value;
}

int pop_back(Deque *dq) {
    if (is_empty(dq)) {
        return -1;
    }
    int value = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    return value;
}

int main(void) {
    Deque dq;
    init_deque(&dq);

    push_back(&dq, 1);
    push_back(&dq, 2);
    push_front(&dq, 0);

    printf("%d\n", pop_front(&dq));
    printf("%d\n", pop_back(&dq));
    return 0;
}
