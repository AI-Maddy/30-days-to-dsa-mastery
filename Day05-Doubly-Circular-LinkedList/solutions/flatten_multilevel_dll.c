/*
Overview:
- Flattens a multilevel doubly linked list (child pointers).
Approach:
- Depth-first traversal using an explicit stack.
Complexity:
- Time: O(n)
- Space: O(n) for stack in worst case
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    struct Node *child;
} Node;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    node->child = NULL;
    return node;
}

Node *flatten(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *stack[100];
    int top = -1;

    Node *cur = head;
    while (cur != NULL) {
        if (cur->child != NULL) {
            if (cur->next != NULL) {
                stack[++top] = cur->next;
            }
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        } else if (cur->next == NULL && top >= 0) {
            cur->next = stack[top--];
            cur->next->prev = cur;
        }
        cur = cur->next;
    }

    return head;
}

void print_list(const Node *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node *head = create_node(1);
    head->next = create_node(2);
    head->next->prev = head;
    head->next->next = create_node(3);
    head->next->next->prev = head->next;

    head->next->child = create_node(7);
    head->next->child->next = create_node(8);
    head->next->child->next->prev = head->next->child;

    head = flatten(head);
    print_list(head);
    return 0;
}
