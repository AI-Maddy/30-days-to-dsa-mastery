/*
Overview:
- Computes the nth Fibonacci number using recursion.
Approach:
- Direct recursive definition: F(n) = F(n-1) + F(n-2).
Complexity:
- Time: O(2^n)
- Space: O(n) due to recursion stack.
*/

#include <stdio.h>

long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int n = 10;
    printf("F(%d) = %lld\n", n, fib(n));
    return 0;
}
