/*
Overview:
- Computes the maximum sum of any subarray of size k.
Approach:
- Maintain a sliding window sum.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int max_sum_subarray_k(const int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        return 0;
    }

    int window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

    int max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    return max_sum;
}

int main(void) {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int k = 3;

    printf("Max sum of size %d = %d\n", k, max_sum_subarray_k(arr, n, k));
    return 0;
}
