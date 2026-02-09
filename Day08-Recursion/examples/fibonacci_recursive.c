/*
Overview:
- Computes nth Fibonacci using recursion.
Approach:
- Return n for n <= 1, else fib(n-1) + fib(n-2).
Complexity:
- Time: O(2^n)
- Space: O(n)
*/

#include <stdio.h>

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    printf("%d\n", fib(10));
    return 0;
}
