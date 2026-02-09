/*
Overview:
- Implements a deque using a doubly linked list.
Approach:
- Push/pop from both ends by updating head/tail.
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
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Deque;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void init_deque(Deque *dq) {
    dq->head = NULL;
    dq->tail = NULL;
}

bool is_empty(const Deque *dq) {
    return dq->head == NULL;
}

void push_front(Deque *dq, int data) {
    Node *node = create_node(data);
    if (!node) {
        return;
    }
    node->next = dq->head;
    if (dq->head != NULL) {
        dq->head->prev = node;
    } else {
        dq->tail = node;
    }
    dq->head = node;
}

void push_back(Deque *dq, int data) {
    Node *node = create_node(data);
    if (!node) {
        return;
    }
    node->prev = dq->tail;
    if (dq->tail != NULL) {
        dq->tail->next = node;
    } else {
        dq->head = node;
    }
    dq->tail = node;
}

int pop_front(Deque *dq) {
    if (is_empty(dq)) {
        return -1;
    }
    Node *node = dq->head;
    int value = node->data;
    dq->head = node->next;
    if (dq->head != NULL) {
        dq->head->prev = NULL;
    } else {
        dq->tail = NULL;
    }
    free(node);
    return value;
}

int pop_back(Deque *dq) {
    if (is_empty(dq)) {
        return -1;
    }
    Node *node = dq->tail;
    int value = node->data;
    dq->tail = node->prev;
    if (dq->tail != NULL) {
        dq->tail->next = NULL;
    } else {
        dq->head = NULL;
    }
    free(node);
    return value;
}

void free_deque(Deque *dq) {
    while (!is_empty(dq)) {
        pop_front(dq);
    }
}

int main(void) {
    Deque dq;
    init_deque(&dq);

    push_front(&dq, 2);
    push_front(&dq, 1);
    push_back(&dq, 3);

    printf("pop_front: %d\n", pop_front(&dq));
    printf("pop_back: %d\n", pop_back(&dq));

    free_deque(&dq);
    return 0;
}
