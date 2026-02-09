/*
Overview:
- Finds the missing number in [0, n] with one number missing.
Approach:
- Use sum formula and subtract actual sum.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int find_missing(const int arr[], int n) {
    long long total = (long long)n * (n + 1) / 2;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return (int)(total - sum);
}

int main(void) {
    int arr[] = {0, 1, 3, 4};
    int n = 4;

    printf("Missing number = %d\n", find_missing(arr, n));
    return 0;
}
