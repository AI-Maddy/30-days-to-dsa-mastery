/*
Overview:
- Removes the nth node from the end of a linked list.
Approach:
- Use a dummy node and two pointers with a gap of n.
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

Node *remove_nth_from_end(Node *head, int n) {
    Node dummy;
    dummy.next = head;

    Node *first = &dummy;
    Node *second = &dummy;

    for (int i = 0; i < n + 1; i++) {
        if (first == NULL) {
            return head;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    Node *to_delete = second->next;
    if (to_delete != NULL) {
        second->next = to_delete->next;
        free(to_delete);
    }

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
    Node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);

    head = remove_nth_from_end(head, 2);
    print_list(head);
    free_list(head);
    return 0;
}
