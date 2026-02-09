/*
Overview:
- Computes sum 1..n recursively.
Approach:
- Base case n == 0; otherwise add n + sum(n-1).
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>

int sum_n(int n) {
    if (n == 0) return 0;
    return n + sum_n(n - 1);
}

int main(void) {
    printf("%d\n", sum_n(10));
    return 0;
}
