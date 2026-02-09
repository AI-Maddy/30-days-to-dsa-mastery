/*
Overview:
- Reverses the words in a sentence in place.
Approach:
- Reverse the entire string, then reverse each word.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <string.h>

void reverse_range(char *s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void reverse_words(char *s) {
    int n = (int)strlen(s);
    reverse_range(s, 0, n - 1);

    int start = 0;
    while (start < n) {
        while (start < n && s[start] == ' ') {
            start++;
        }
        int end = start;
        while (end < n && s[end] != ' ') {
            end++;
        }
        if (start < end) {
            reverse_range(s, start, end - 1);
        }
        start = end;
    }
}

int main(void) {
    char s[] = "hello world from c";
    reverse_words(s);
    printf("%s\n", s);
    return 0;
}
