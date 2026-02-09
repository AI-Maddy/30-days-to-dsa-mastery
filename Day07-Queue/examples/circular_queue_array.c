/*
Overview:
- Implements a circular queue using a fixed-size array.
Approach:
- Use front, rear, and size with modulo arithmetic.
Complexity:
- Time: O(1) per enqueue/dequeue
- Space: O(n)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 5

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

bool is_empty(const Queue *q) {
    return q->size == 0;
}

bool is_full(const Queue *q) {
    return q->size == MAX;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
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
