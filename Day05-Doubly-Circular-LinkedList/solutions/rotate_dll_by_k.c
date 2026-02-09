/*
Overview:
- Rotates a doubly linked list to the right by k nodes.
Approach:
- Find length, connect tail to head, then break at new tail.
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

Node *rotate_right(Node *head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    Node *tail = head;
    int len = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    k %= len;
    if (k == 0) {
        return head;
    }

    tail->next = head;
    head->prev = tail;

    int steps_to_new_head = len - k;
    Node *new_tail = tail;
    for (int i = 0; i < steps_to_new_head; i++) {
        new_tail = new_tail->next;
    }

    Node *new_head = new_tail->next;
    new_tail->next = NULL;
    new_head->prev = NULL;

    return new_head;
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
    head->next->next->next = create_node(4);
    head->next->next->next->prev = head->next->next;

    head = rotate_right(head, 2);
    print_list(head);
    free_list(head);
    return 0;
}
