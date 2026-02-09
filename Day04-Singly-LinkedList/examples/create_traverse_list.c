/*
Overview:
- Creates a singly linked list and traverses it.
Approach:
- Append nodes to the tail and print.
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

void append(Node **head, int data) {
    Node *node = create_node(data);
    if (!node) {
        return;
    }

    if (*head == NULL) {
        *head = node;
        return;
    }

    Node *cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = node;
}

void print_list(const Node *head) {
    const Node *cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    Node *head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    print_list(head);
    free_list(head);
    return 0;
}
