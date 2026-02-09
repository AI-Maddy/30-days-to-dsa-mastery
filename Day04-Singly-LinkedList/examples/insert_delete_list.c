/*
Overview:
- Demonstrates insert-at-head and delete-by-key in a singly linked list.
Approach:
- Head insertion is O(1); deletion scans for the key.
Complexity:
- Time: O(n) for delete
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

void insert_head(Node **head, int data) {
    Node *node = create_node(data);
    if (!node) {
        return;
    }
    node->next = *head;
    *head = node;
}

void delete_key(Node **head, int key) {
    Node *cur = *head;
    Node *prev = NULL;

    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
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
    Node *head = NULL;
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);

    print_list(head);
    delete_key(&head, 2);
    print_list(head);

    free_list(head);
    return 0;
}
