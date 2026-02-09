/*
Overview:
- Finds the next greater element for each array element.
Approach:
- Use a stack of indices while scanning from right to left.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} IntStack;

void init_stack(IntStack *s) {
    s->top = -1;
}

int is_empty(const IntStack *s) {
    return s->top == -1;
}

void push(IntStack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(IntStack *s) {
    return s->data[(s->top)--];
}

int peek(const IntStack *s) {
    return s->data[s->top];
}

void next_greater(const int arr[], int n, int result[]) {
    IntStack s;
    init_stack(&s);

    for (int i = n - 1; i >= 0; i--) {
        while (!is_empty(&s) && arr[peek(&s)] <= arr[i]) {
            pop(&s);
        }
        result[i] = is_empty(&s) ? -1 : arr[peek(&s)];
        push(&s, i);
    }
}

int main(void) {
    int arr[] = {4, 5, 2, 10, 8};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int result[5];

    next_greater(arr, n, result);
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }

    return 0;
}
