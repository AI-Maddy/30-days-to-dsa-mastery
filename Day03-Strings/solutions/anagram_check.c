/*
Overview:
- Checks if two lowercase strings are anagrams.
Approach:
- Frequency counts for 26 letters.
Complexity:
- Time: O(n + m)
- Space: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

bool are_anagrams(const char *a, const char *b) {
    int freq[26] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        freq[a[i] - 'a']++;
    }
    for (int i = 0; b[i] != '\0'; i++) {
        freq[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    const char *a = "triangle";
    const char *b = "integral";
    printf("%s\n", are_anagrams(a, b) ? "anagrams" : "not anagrams");
    return 0;
}
