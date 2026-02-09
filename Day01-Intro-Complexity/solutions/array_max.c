/*
Overview:
- Finds the maximum element in an array.
Approach:
- Track the current max while scanning once.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int array_max(const int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main(void) {
    int arr[] = {12, 7, 19, 4, 25};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    int max_val = array_max(arr, n);
    printf("Max value = %d\n", max_val);
    return 0;
}
