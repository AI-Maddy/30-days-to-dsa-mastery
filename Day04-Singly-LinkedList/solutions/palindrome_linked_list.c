/*
Overview:
- Checks if a linked list is a palindrome.
Approach:
- Find middle, reverse second half, then compare halves.
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

Node *reverse_list(Node *head) {
    Node *prev = NULL;
    Node *cur = head;

    while (cur != NULL) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

bool is_palindrome(Node *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second_half = reverse_list(slow);
    Node *p1 = head;
    Node *p2 = second_half;
    bool ok = true;

    while (p2 != NULL) {
        if (p1->data != p2->data) {
            ok = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    reverse_list(second_half);
    return ok;
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
    head->next->next = create_node(2);
    head->next->next->next = create_node(1);

    printf("Palindrome? %s\n", is_palindrome(head) ? "yes" : "no");
    free_list(head);
    return 0;
}
