/*
Overview:
- Rotates an array to the right by k positions.
Approach:
- Reverse the whole array, then reverse first k and remaining part.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

void reverse(int arr[], int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void rotate_right(int arr[], int n, int k) {
    if (n == 0) {
        return;
    }

    k %= n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int k = 3;

    rotate_right(arr, n, k);
    print_array(arr, n);
    return 0;
}
