/*
Overview:
- Finds the first non-repeating character in a string.
Approach:
- Count frequencies, then scan to find first with count 1.
Complexity:
- Time: O(n)
- Space: O(1) for ASCII
*/

#include <stdio.h>

char first_non_repeating(const char *s) {
    int freq[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        freq[ch]++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (freq[ch] == 1) {
            return (char)ch;
        }
    }

    return '\0';
}

int main(void) {
    const char *s = "swiss";
    char ch = first_non_repeating(s);

    if (ch == '\0') {
        printf("No unique character\n");
    } else {
        printf("First unique character: %c\n", ch);
    }

    return 0;
}
