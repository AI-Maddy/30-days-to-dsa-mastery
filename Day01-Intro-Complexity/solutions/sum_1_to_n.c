/*
Overview:
- Computes the sum from 1 to n using a loop.
Approach:
- Iterate i from 1 to n and accumulate.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

long long sum_1_to_n(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main(void) {
    int n = 10;
    long long result = sum_1_to_n(n);
    printf("Sum 1..%d = %lld\n", n, result);
    return 0;
}
