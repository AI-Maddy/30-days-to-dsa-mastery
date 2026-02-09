/*
Overview:
- Reverses a doubly linked list.
Approach:
- Swap next/prev pointers while traversing.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

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

Node *reverse_list(Node *head) {
    Node *cur = head;
    Node *temp = NULL;

    while (cur != NULL) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
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

void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    Node *head = create_node(1);
    head->next = create_node(2);
    head->next->prev = head;
    head->next->next = create_node(3);
    head->next->next->prev = head->next;

    print_list(head);
    head = reverse_list(head);
    print_list(head);

    free_list(head);
    return 0;
}
