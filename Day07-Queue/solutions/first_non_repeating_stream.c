/*
Overview:
- Prints the first non-repeating character after each input character.
Approach:
- Use a queue to store candidates and a frequency table.
Complexity:
- Time: O(n)
- Space: O(1) for ASCII
*/

#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void) {
    const char *stream = "aabc";
    int freq[MAX] = {0};
    char queue[100];
    int front = 0;
    int rear = 0;

    for (int i = 0; stream[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)stream[i];
        freq[ch]++;
        queue[rear++] = (char)ch;

        while (front < rear && freq[(unsigned char)queue[front]] > 1) {
            front++;
        }

        if (front == rear) {
            printf("-1 ");
        } else {
            printf("%c ", queue[front]);
        }
    }

    printf("\n");
    return 0;
}
