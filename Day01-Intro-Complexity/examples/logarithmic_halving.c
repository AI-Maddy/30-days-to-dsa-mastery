/*
Overview:
- Counts how many times a number can be halved until it becomes 1.
Approach:
- Repeatedly divide by 2.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void) {
    int n = 1000;
    int steps = 0;

    while (n > 1) {
        n /= 2;
        steps++;
    }

    printf("Halving steps = %d\n", steps);
    return 0;
}
