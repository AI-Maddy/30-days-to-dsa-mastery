/*
Overview:
- Reverses a string using recursion.
Approach:
- Swap ends, then recurse inward.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>
#include <string.h>

void reverse(char *s, int left, int right) {
    if (left >= right) return;
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    reverse(s, left + 1, right - 1);
}

int main(void) {
    char s[] = "recursion";
    reverse(s, 0, (int)strlen(s) - 1);
    printf("%s\n", s);
    return 0;
}
