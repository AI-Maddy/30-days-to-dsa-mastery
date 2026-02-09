/*
Overview:
- Finds the maximum of every subarray of size k.
Approach:
- Maintain a deque of indices in decreasing order.
Complexity:
- Time: O(n)
- Space: O(k)
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Deque;

void init_deque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
}

int is_empty(const Deque *dq) {
    return dq->front > dq->rear;
}

int peek_front(const Deque *dq) {
    return dq->data[dq->front];
}

int peek_back(const Deque *dq) {
    return dq->data[dq->rear];
}

void push_back(Deque *dq, int value) {
    dq->data[++(dq->rear)] = value;
}

void pop_back(Deque *dq) {
    dq->rear--;
}

void pop_front(Deque *dq) {
    dq->front++;
}

void sliding_window_max(const int arr[], int n, int k) {
    Deque dq;
    init_deque(&dq);

    for (int i = 0; i < n; i++) {
        while (!is_empty(&dq) && peek_front(&dq) <= i - k) {
            pop_front(&dq);
        }
        while (!is_empty(&dq) && arr[peek_back(&dq)] <= arr[i]) {
            pop_back(&dq);
        }
        push_back(&dq, i);

        if (i >= k - 1) {
            printf("%d ", arr[peek_front(&dq)]);
        }
    }
    printf("\n");
}

int main(void) {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int k = 3;

    sliding_window_max(arr, n, k);
    return 0;
}
