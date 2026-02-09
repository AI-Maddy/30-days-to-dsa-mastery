/*
Overview:
- Merges two sorted linked lists into one sorted list.
Approach:
- Iterative merge using a dummy head.
Complexity:
- Time: O(n + m)
- Space: O(1) extra
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

Node *merge_sorted(Node *a, Node *b) {
    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != NULL) ? a : b;
    return dummy.next;
}

void print_list(const Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
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
    Node *a = create_node(1);
    a->next = create_node(3);
    a->next->next = create_node(5);

    Node *b = create_node(2);
    b->next = create_node(4);
    b->next->next = create_node(6);

    Node *merged = merge_sorted(a, b);
    print_list(merged);
    free_list(merged);
    return 0;
}
