/*
Overview:
- Prints moves for Tower of Hanoi.
Approach:
- Move n-1 to auxiliary, move largest, move n-1 to target.
Complexity:
- Time: O(2^n)
- Space: O(n)
*/

#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    printf("Move %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main(void) {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}
