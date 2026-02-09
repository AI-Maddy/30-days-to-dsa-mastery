/*
Overview:
- Demonstrates a constant-time array access.
Approach:
- Read a fixed index from a static array.
Complexity:
- Time: O(1)
- Space: O(1)
*/

#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int index = 3;

    /* Direct indexing is constant time. */
    int value = arr[index];

    printf("Value at index %d is %d\n", index, value);
    return 0;
}
