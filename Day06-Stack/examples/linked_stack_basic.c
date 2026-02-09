/*
Overview:
- Implements a stack using a linked list.
Approach:
- Push/pop at the head.
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
    Node *top;
} Stack;

void init_stack(Stack *s) {
    s->top = NULL;
}

bool is_empty(const Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return;
    }
    node->data = value;
    node->next = s->top;
    s->top = node;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    Node *node = s->top;
    int value = node->data;
    s->top = node->next;
    free(node);
    return value;
}

void free_stack(Stack *s) {
    while (!is_empty(s)) {
        pop(s);
    }
}

int main(void) {
    Stack s;
    init_stack(&s);

    push(&s, 5);
    push(&s, 7);
    printf("pop: %d\n", pop(&s));

    free_stack(&s);
    return 0;
}
