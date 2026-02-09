/*
Overview:
- Finds the length of the longest substring without repeating characters.
Approach:
- Sliding window with frequency array (ASCII).
Complexity:
- Time: O(n)
- Space: O(1) for fixed alphabet size
*/

#include <stdio.h>
#include <string.h>

int longest_unique_substring(const char *s) {
    int freq[256] = {0};
    int left = 0;
    int max_len = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char ch = (unsigned char)s[right];
        freq[ch]++;

        while (freq[ch] > 1) {
            unsigned char left_ch = (unsigned char)s[left];
            freq[left_ch]--;
            left++;
        }

        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    return max_len;
}

int main(void) {
    const char *s = "abcabcbb";
    printf("Longest unique substring length = %d\n", longest_unique_substring(s));
    return 0;
}
