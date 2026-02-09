/*
Overview:
- Splits a circular linked list into two halves.
Approach:
- Use slow/fast pointers to find the midpoint.
Complexity:
- Time: O(n)
- Space: O(1)
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

void split_circular(Node *head, Node **head1, Node **head2) {
    if (head == NULL) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;

    if (fast->next->next == head) {
        fast = fast->next;
    }
    fast->next = *head2;
}

void print_circular(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *cur = head;
    do {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("(back)\n");
}

int main(void) {
    Node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = head;

    Node *first = NULL;
    Node *second = NULL;
    split_circular(head, &first, &second);

    print_circular(first);
    print_circular(second);
    return 0;
}
