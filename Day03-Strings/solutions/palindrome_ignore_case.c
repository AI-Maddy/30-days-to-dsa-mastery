/*
Overview:
- Checks if a string is a palindrome ignoring case and non-alphanumerics.
Approach:
- Two pointers that skip non-alphanumeric characters.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_palindrome_clean(const char *s) {
    int left = 0;
    int right = (int)strlen(s) - 1;

    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) {
            left++;
        }
        while (left < right && !isalnum((unsigned char)s[right])) {
            right--;
        }

        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(void) {
    const char *s = "A man, a plan, a canal: Panama";
    printf("%s\n", is_palindrome_clean(s) ? "palindrome" : "not palindrome");
    return 0;
}
