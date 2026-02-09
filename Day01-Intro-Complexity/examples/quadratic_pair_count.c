/*
Overview:
- Counts the number of unique pairs (i, j) with i < j.
Approach:
- Nested loops over all pairs.
Complexity:
- Time: O(n^2)
- Space: O(1)
*/

#include <stdio.h>

int main(void) {
    int arr[] = {1, 3, 5, 7};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int pairs = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs++;
        }
    }

    printf("Number of unique pairs = %d\n", pairs);
    return 0;
}
