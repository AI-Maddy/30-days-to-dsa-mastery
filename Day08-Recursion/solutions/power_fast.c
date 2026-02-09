/*
Overview:
- Computes a^b using fast recursion.
Approach:
- Use exponentiation by squaring.
Complexity:
- Time: O(log b)
- Space: O(log b)
*/

#include <stdio.h>

long long power(long long a, long long b) {
    if (b == 0) return 1;
    long long half = power(a, b / 2);
    if (b % 2 == 0) return half * half;
    return half * half * a;
}

int main(void) {
    printf("%lld\n", power(2, 10));
    return 0;
}
