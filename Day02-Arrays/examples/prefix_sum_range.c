/*
Overview:
- Builds a prefix sum array for fast range sum queries.
Approach:
- Precompute prefix sums; query in O(1).
Complexity:
- Time: O(n) preprocessing, O(1) per query
- Space: O(n)
*/

#include <stdio.h>

void build_prefix_sum(const int arr[], int prefix[], int n) {
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

int range_sum(const int prefix[], int left, int right) {
    if (left == 0) {
        return prefix[right];
    }
    return prefix[right] - prefix[left - 1];
}

int main(void) {
    int arr[] = {3, 4, 2, 1, 6};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int prefix[5];

    build_prefix_sum(arr, prefix, n);
    printf("Sum [1..3] = %d\n", range_sum(prefix, 1, 3));
    return 0;
}
