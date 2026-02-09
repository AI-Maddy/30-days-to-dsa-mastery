/*
Overview:
- Computes factorial using recursion.
Approach:
- Use base case n <= 1; multiply n by factorial(n-1).
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>

long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main(void) {
    int n = 6;
    printf("%lld\n", fact(n));
    return 0;
}
