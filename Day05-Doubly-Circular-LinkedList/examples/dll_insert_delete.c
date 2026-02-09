/*
Overview:
- Demonstrates insertion and deletion in a doubly linked list.
Approach:
- Insert at head and tail, delete by key.
Complexity:
- Time: O(1) for head/tail insert, O(n) for delete
- Space: O(n)
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

void insert_head(Node **head, int data) {
    Node *node = create_node(data);
    if (!node) {
        return;
    }
    node->next = *head;
    if (*head != NULL) {
        (*head)->prev = node;
    }
    *head = node;
}

void insert_tail(Node **head, int data) {
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
    node->prev = cur;
}

void delete_key(Node **head, int key) {
    Node *cur = *head;

    while (cur != NULL && cur->data != key) {
        cur = cur->next;
    }
    if (cur == NULL) {
        return;
    }

    if (cur->prev != NULL) {
        cur->prev->next = cur->next;
    } else {
        *head = cur->next;
    }

    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }

    free(cur);
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
    Node *head = NULL;
    insert_head(&head, 2);
    insert_head(&head, 1);
    insert_tail(&head, 3);

    print_list(head);
    delete_key(&head, 2);
    print_list(head);

    free_list(head);
    return 0;
}
