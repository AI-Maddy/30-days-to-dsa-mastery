/*
Overview:
- Implements a queue using a linked list.
Approach:
- Maintain front and rear pointers.
Complexity:
- Time: O(1) per operation
- Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

bool is_empty(const Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return;
    }
    node->data = value;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = node;
        q->rear = node;
        return;
    }

    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue empty\n");
        return -1;
    }

    Node *node = q->front;
    int value = node->data;
    q->front = node->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(node);
    return value;
}

void free_queue(Queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
}

int main(void) {
    Queue q;
    init_queue(&q);

    enqueue(&q, 5);
    enqueue(&q, 6);
    printf("%d\n", dequeue(&q));

    free_queue(&q);
    return 0;
}
