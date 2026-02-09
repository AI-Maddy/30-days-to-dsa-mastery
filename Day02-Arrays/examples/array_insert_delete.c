/*
Overview:
- Demonstrates insert and delete operations on a fixed-size array.
Approach:
- Shift elements to make space or remove an element.
Complexity:
- Time: O(n) for insert/delete at a position
- Space: O(1)
*/

#include <stdio.h>

void insert_at(int arr[], int *n, int capacity, int index, int value) {
    if (*n >= capacity || index < 0 || index > *n) {
        return;
    }

    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*n)++;
}

void delete_at(int arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        return;
    }

    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5;

    insert_at(arr, &n, 10, 2, 99);
    print_array(arr, n);

    delete_at(arr, &n, 4);
    print_array(arr, n);

    return 0;
}
