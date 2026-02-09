/*
Overview:
- Searches for a target in a sorted array.
Approach:
- Iterative binary search using two pointers.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int binary_search(const int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void) {
    int arr[] = {1, 4, 7, 9, 12, 15, 20};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int target = 12;

    int index = binary_search(arr, n, target);
    if (index >= 0) {
        printf("Found %d at index %d\n", target, index);
    } else {
        printf("Target not found\n");
    }

    return 0;
}
