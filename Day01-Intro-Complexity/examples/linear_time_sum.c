/*
Overview:
- Sums all elements in an array using a single loop.
Approach:
- Iterate once and accumulate.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int main(void) {
    int arr[] = {2, 4, 6, 8, 10};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);
    return 0;
}
