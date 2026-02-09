/*
Overview:
- Reverses a string in place using two pointers.
Approach:
- Swap from both ends until pointers meet.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <string.h>

void reverse_in_place(char *s) {
    int left = 0;
    int right = (int)strlen(s) - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main(void) {
    char s[] = "hello";
    reverse_in_place(s);
    printf("%s\n", s);
    return 0;
}
