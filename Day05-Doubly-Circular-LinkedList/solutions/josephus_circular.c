/*
Overview:
- Solves the Josephus problem using a circular linked list.
Approach:
- Move k-1 steps and remove the next node repeatedly.
Complexity:
- Time: O(n * k)
- Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int josephus(int n, int k) {
    Node *head = create_node(1);
    Node *prev = head;
    for (int i = 2; i <= n; i++) {
        prev->next = create_node(i);
        prev = prev->next;
    }
    prev->next = head;

    Node *cur = head;
    Node *tail = prev;

    while (cur->next != cur) {
        for (int i = 1; i < k; i++) {
            tail = cur;
            cur = cur->next;
        }

        tail->next = cur->next;
        free(cur);
        cur = tail->next;
    }

    int result = cur->data;
    free(cur);
    return result;
}

int main(void) {
    int n = 7;
    int k = 3;
    printf("Survivor = %d\n", josephus(n, k));
    return 0;
}
