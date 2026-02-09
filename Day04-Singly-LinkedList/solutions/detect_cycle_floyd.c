/*
Overview:
- Detects if a linked list has a cycle.
Approach:
- Floyd's cycle detection (slow/fast pointers).
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool has_cycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main(void) {
    Node *a = create_node(1);
    Node *b = create_node(2);
    Node *c = create_node(3);
    a->next = b;
    b->next = c;
    c->next = b; /* create a cycle */

    printf("Has cycle? %s\n", has_cycle(a) ? "yes" : "no");

    /* No free here because list is cyclic in this demo. */
    return 0;
}
