/*
Overview:
- Builds a circular singly linked list and traverses it once.
Approach:
- Stop after returning to the head.
Complexity:
- Time: O(n)
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

int main(void) {
    Node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = head; /* circular link */

    Node *cur = head;
    if (cur != NULL) {
        do {
            printf("%d -> ", cur->data);
            cur = cur->next;
        } while (cur != head);
    }
    printf("(back to head)\n");

    /* No free in this small demo because it's circular. */
    return 0;
}
