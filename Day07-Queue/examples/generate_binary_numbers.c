/*
Overview:
- Generates binary numbers from 1 to n using a queue.
Approach:
- Start with "1", then append "0" and "1" for each dequeued string.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {
    char queue[MAX][32];
    int front = 0;
    int rear = 0;

    int n = 10;
    strcpy(queue[rear++], "1");

    for (int i = 0; i < n; i++) {
        char current[32];
        strcpy(current, queue[front++]);
        printf("%s ", current);

        char next_zero[32];
        char next_one[32];
        snprintf(next_zero, sizeof(next_zero), "%s0", current);
        snprintf(next_one, sizeof(next_one), "%s1", current);

        strcpy(queue[rear++], next_zero);
        strcpy(queue[rear++], next_one);
    }

    printf("\n");
    return 0;
}
