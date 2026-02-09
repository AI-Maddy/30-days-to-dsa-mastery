/*
Overview:
- Checks if a string is a palindrome (case sensitive).
Approach:
- Two pointers from both ends.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char *s) {
    int left = 0;
    int right = (int)strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(void) {
    const char *word = "level";
    printf("%s -> %s\n", word, is_palindrome(word) ? "palindrome" : "not palindrome");
    return 0;
}
