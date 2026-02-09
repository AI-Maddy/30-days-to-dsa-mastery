/*
Overview:
- Counts subsets that sum to target.
Approach:
- Include/exclude each element recursively.
Complexity:
- Time: O(2^n)
- Space: O(n)
*/

#include <stdio.h>

int count_subsets(const int arr[], int n, int idx, int target) {
    if (idx == n) return target == 0;
    return count_subsets(arr, n, idx + 1, target) +
           count_subsets(arr, n, idx + 1, target - arr[idx]);
}

int main(void) {
    int arr[] = {1, 2, 3};
    printf("%d\n", count_subsets(arr, 3, 0, 3));
    return 0;
}
