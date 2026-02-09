# Day 14 — Tries (Prefix Trees)

## 🎯 Mastery Goals
- Understand trie structure and prefix-based operations 
- Implement insert, search, and prefix matching efficiently
- Master string-related algorithms using tries
- Solve autocomplete and dictionary problems
- Recognize when tries outperform hash tables

---

## 1️⃣ What is a Trie?

A **trie** (prefix tree) is a tree data structure for storing strings where:
- Each node represents a character
- Root is empty
- Path from root to node = prefix
- Enables O(m) operations where m = string length

```text
Trie storing: ["cat", "car", "card", "dog", "door"]

        (root)
       /      \
      c        d
      |        |
      a        o
     / \       |
    t   r      g   o
        |          |
        d          r
```

### Why Trie?
- **Prefix operations:** Faster than hash table for prefix matching
- **Autocomplete:** Natural fit
- **Space efficient:** Shared prefixes
- **No hash collisions**

---

## 2️⃣ Trie Implementation

```c
#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    
    return node;
}

// Insert — O(m) where m = length of word
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL)
            current->children[index] = createNode();
        
        current = current->children[index];
    }
    
    current->isEndOfWord = true;
}

// Search — O(m)
bool search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL)
            return false;
        
        current = current->children[index];
    }
    
    return current->isEndOfWord;
}

// StartsWith (Prefix Search) — O(m)
bool startsWith(TrieNode* root, const char* prefix) {
    TrieNode* current = root;
    
    for (int i = 0; prefix[i]; i++) {
        int index = prefix[i] - 'a';
        
        if (current->children[index] == NULL)
            return false;
        
        current = current->children[index];
    }
    
    return true;
}
```

---

## 3️⃣ Advanced Trie Operations

### Delete Word
```c
bool deleteHelper(TrieNode* node, const char* word, int depth) {
    if (node == NULL) return false;
    
    // Base case: reached end of word
    if (word[depth] == '\0') {
        if (!node->isEndOfWord) return false;
        
        node->isEndOfWord = false;
        
        // If node has no children, can be deleted
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (node->children[i]) return false;
        
        return true;
    }
    
    int index = word[depth] - 'a';
    if (deleteHelper(node->children[index], word, depth + 1)) {
        free(node->children[index]);
        node->children[index] = NULL;
        
        // Check if current node can also be deleted
        if (!node->isEndOfWord) {
            for (int i = 0; i < ALPHABET_SIZE; i++)
                if (node->children[i]) return false;
            return true;
        }
    }
    
    return false;
}

void deleteWord(TrieNode* root, const char* word) {
    deleteHelper(root, word, 0);
}
```

### Count Words with Prefix
```c
int countWordsWithPrefix(TrieNode* root, const char* prefix) {
    TrieNode* current = root;
    
    // Navigate to prefix end
    for (int i = 0; prefix[i]; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    
    // Count all words from this point
    return countWords(current);
}

int countWords(TrieNode* node) {
    if (node == NULL) return 0;
    
    int count = node->isEndOfWord ? 1 : 0;
    
    for (int i = 0; i < ALPHABET_SIZE; i++)
        count += countWords(node->children[i]);
    
    return count;
}
```

---

## 4️⃣ Interview Problems

### Problem 1: Autocomplete System
```c
void autocomplete(TrieNode* root, const char* prefix) {
    TrieNode* current = root;
    
    // Navigate to prefix
    for (int i = 0; prefix[i]; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            printf("No suggestions\n");
            return;
        }
        current = current->children[index];
    }
    
    // Print all words with this prefix
    char buffer[100];
    strcpy(buffer, prefix);
    printAllWords(current, buffer, strlen(prefix));
}

void printAllWords(TrieNode* node, char* buffer, int depth) {
    if (node->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            buffer[depth] = 'a' + i;
            printAllWords(node->children[i], buffer, depth + 1);
        }
    }
}
```

### Problem 2: Longest Common Prefix
```c
char* longestCommonPrefix(char* words[], int n) {
    if (n == 0) return "";
    
    TrieNode* root = createNode();
    
    // Insert all words
    for (int i = 0; i < n; i++)
        insert(root, words[i]);
    
    char* prefix = (char*)malloc(100);
    int len = 0;
    TrieNode* current = root;
    
    // Traverse while only one child exists
    while (current) {
        int count = 0, index = -1;
        
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (current->children[i]) {
                count++;
                index = i;
            }
        }
        
        if (count != 1 || current->isEndOfWord)
            break;
        
        prefix[len++] = 'a' + index;
        current = current->children[index];
    }
    
    prefix[len] = '\0';
    return prefix;
}
```

---

## 🧪 Practice Exercises

### Exercise 1: Word Search II
Find all words from dictionary in 2D board

### Exercise 2: Replace Words
Replace words with shortest root from dictionary

### Exercise 3: Design Search Autocomplete System
Implement with ranking and frequency

---

## 🎯 Interview Tips

✓ **Space:** O(ALPHABET_SIZE × N × M) where N=words, M=avg length  
✓ **Use when:** Prefix operations, autocomplete, spell check  
✓ **Not for:** Simple membership (use hash table)  
✓ **Optimization:** Compress paths with only one child  

---

## 📚 Key Takeaways

- Trie: Tree for strings, each edge labeled with character
- Operations: O(m) where m = string length
- Perfect for: Prefix search, autocomplete, spell check
- Space trade-off: Uses more memory for fast prefix operations

---

**Next:** Day 15 - Searching Algorithms
