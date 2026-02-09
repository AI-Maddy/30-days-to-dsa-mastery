# Day 03 — Strings

## 🎯 Mastery Goals
- Understand string representation in memory
- Master string manipulation techniques
- Learn pattern matching algorithms
- Handle common string interview problems
- Recognize string-specific optimization opportunities

---

## 1️⃣ What is a String?

A string is an **array of characters** terminated by a null character (`\0` in C).

```c
char str[] = "Hello";

Memory Layout:
┌───┬───┬───┬───┬───┬─────┐
│ H │ e │ l │ l │ o │ \0  │
└───┴───┴───┴───┴───┴─────┘
  0   1   2   3   4    5

Length = 5, but array size = 6
```

---

## 2️⃣ String Operations Complexity

| Operation | Time | Notes |
|-----------|------|-------|
| **Access** `str[i]` | O(1) | Direct index |
| **Length** `strlen()` | O(n) | Must scan to find `\0` |
| **Compare** | O(n) | Character by character |
| **Concatenate** | O(n+m) | Copy both strings |
| **Substring** | O(k) | Copy k characters |
| **Search** | O(n×m) | Naive pattern matching |
| **Search** (KMP) | O(n+m) | Linear time algorithm |

---

## 3️⃣ Common String Patterns

### Pattern 1: Two Pointers (Palindrome Check)
```c
// O(n) time, O(1) space
bool isPalindrome(char* str) {
    int left = 0, right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}
```

### Pattern 2: Sliding Window (Longest Substring Without Repeating)
```c
// O(n) time, O(1) space (assuming ASCII)
int lengthOfLongestSubstring(char* s) {
    int freq[256] = {0};
    int left = 0, maxLen = 0;
    
    for (int right = 0; s[right]; right++) {
        freq[s[right]]++;
        
        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }
        
        int currentLen = right - left + 1;
        if (currentLen > maxLen)
            maxLen = currentLen;
    }
    return maxLen;
}
```

### Pattern 3: Character Frequency (Anagram Check)
```c
// O(n) time, O(1) space
bool areAnagrams(char* s1, char* s2) {
    int freq[26] = {0};
    
    // Count s1
    for (int i = 0; s1[i]; i++)
        freq[s1[i] - 'a']++;
    
    // Subtract s2
    for (int i = 0; s2[i]; i++)
        freq[s2[i] - 'a']--;
    
    // Check if all zeros
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0) return false;
    
    return true;
}
```

---

## 4️⃣ String Reversal Techniques

### Method 1: Two Pointers
```c
void reverse(char* str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++; right--;
    }
}
```

### Method 2: Reverse Words in String
```c
// "hello world" → "world hello"
// 1. Reverse entire string: "dlrow olleh"
// 2. Reverse each word: "world hello"
```

---

## 5️⃣ Pattern Matching

### Naive Approach
```c
// O(n × m) time
int strStr(char* haystack, char* needle) {
    int n = strlen(haystack), m = strlen(needle);
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == m) return i;  // Match found
    }
    return -1;
}
```

### KMP Algorithm (Advanced)
- Preprocesses pattern, O(m) time
- Matching: O(n) time
- **Total: O(n + m)** — optimal!

---

## 🧪 Common Interview Problems

### Problem 1: Valid Parentheses
Check if brackets are balanced: "({[]})" → valid

### Problem 2: Longest Palindromic Substring
Find longest palindrome in a string

### Problem 3: Group Anagrams
Group words that are anagrams of each other

---

## 🎯 Interview Tips

✓ **Ask about:** Character set (ASCII/Unicode)? Case sensitive?  
✓ **Common tricks:** Use frequency arrays, two pointers  
✓ **Watch for:** Null terminator, string immutability (in some languages)  
✓ **Optimize:** In-place when possible  

---

## 📚 Key Takeaways

- Strings are character arrays with `\0` terminator
- Master two pointers, sliding window, frequency counting
- KMP for efficient pattern matching
- Many problems reducible to array techniques

---

**Next:** Day 04 - Linked Lists (dynamic data structure, no contiguous memory)
