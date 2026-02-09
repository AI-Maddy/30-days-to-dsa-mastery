# Day 13 — Hashing

## 🎯 Mastery Goals
- Understand hash functions and collision resolution
- Master hash table operations and complexities
- Implement chaining and open addressing
- Solve hash-based interview problems efficiently
- Recognize when hashing is the optimal approach

---

## 1️⃣ What is Hashing?

**Hashing** maps keys to array indices using a **hash function**, enabling O(1) average-case operations.

```text
Key → Hash Function → Index → Value

Example:
"apple" → hash("apple") % 10 → index 3 → value: 5
"banana" → hash("banana") % 10 → index 7 → value: 2
```

### Why Hashing?
| Operation | Array (unsorted) | Hash Table | BST |
|-----------|------------------|------------|-----|
| **Search** | O(n) | O(1) avg | O(log n) |
| **Insert** | O(1) | O(1) avg | O(log n) |
| **Delete** | O(n) | O(1) avg | O(log n) |
| **Ordered traversal** | O(n log n) | O(n log n) | O(n) |

**Use hashing when:**
- Need fast lookups
- Order doesn't matter
- Keys are hashable

---

## 2️⃣ Hash Functions

A good hash function should:
1. **Fast to compute** — O(1)
2. **Uniform distribution** — Minimize collisions
3. **Deterministic** — Same input → same output

### Common Hash Functions

```c
// Division Method (most common)
int hashDiv(int key, int tableSize) {
    return key % tableSize;
}

// Multiplication Method
int hashMult(int key, int tableSize) {
    double A = 0.6180339887;  // (sqrt(5) - 1) / 2
    double temp = key * A;
    temp = temp - (int)temp;  // Fractional part
    return (int)(tableSize * temp);
}

// String Hashing (Polynomial Rolling Hash)
int hashString(char* str, int tableSize) {
    unsigned long hash = 0;
    int p = 31;  // Prime number
    int m = 1e9 + 9;  // Large prime
    
    for (int i = 0; str[i]; i++) {
        hash = (hash * p + str[i]) % m;
    }
    return hash % tableSize;
}

// FNV-1a Hash (Fast, good distribution)
unsigned int fnv1aHash(char* str, int tableSize) {
    unsigned int hash = 2166136261u;
    while (*str) {
        hash ^= *str++;
        hash *= 16777619;
    }
    return hash % tableSize;
}
```

---

## 3️⃣ Collision Resolution

**Collision:** Two keys hash to same index

### Method 1: Chaining (Linked Lists)

```c
#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[TABLE_SIZE];
} HashTable;

void initHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
}

// Insert — O(1) average
void insert(HashTable* ht, int key, int value) {
    int index = key % TABLE_SIZE;
    
    // Check if key exists
    Node* current = ht->buckets[index];
    while (current) {
        if (current->key == key) {
            current->value = value;  // Update
            return;
        }
        current = current->next;
    }
    
    // Insert at beginning
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
}

// Search — O(1) average, O(n) worst
int search(HashTable* ht, int key) {
    int index = key % TABLE_SIZE;
    Node* current = ht->buckets[index];
    
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;  // Not found
}

// Delete — O(1) average
void delete(HashTable* ht, int key) {
    int index = key % TABLE_SIZE;
    Node* current = ht->buckets[index];
    Node* prev = NULL;
    
    while (current) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Visualization:
// Index 0: → [5, "apple"] → [15, "orange"] → NULL
// Index 1: → NULL
// Index 2: → [12, "banana"] → NULL
// ...
```

### Method 2: Open Addressing (Linear Probing)

```c
#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct {
    int keys[TABLE_SIZE];
    int values[TABLE_SIZE];
} OpenAddressHashTable;

void initOAHashTable(OpenAddressHashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->keys[i] = EMPTY;
    }
}

// Insert — O(1) average
void insertOA(OpenAddressHashTable* ht, int key, int value) {
    int index = key % TABLE_SIZE;
    int startIndex = index;
    
    do {
        if (ht->keys[index] == EMPTY || ht->keys[index] == DELETED) {
            ht->keys[index] = key;
            ht->values[index] = value;
            return;
        }
        if (ht->keys[index] == key) {
            ht->values[index] = value;  // Update
            return;
        }
        index = (index + 1) % TABLE_SIZE;  // Linear probing
    } while (index != startIndex);
    
    printf("Hash table full!\n");
}

// Search — O(1) average
int searchOA(OpenAddressHashTable* ht, int key) {
    int index = key % TABLE_SIZE;
    int startIndex = index;
    
    do {
        if (ht->keys[index] == EMPTY) {
            return -1;  // Not found
        }
        if (ht->keys[index] == key) {
            return ht->values[index];
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);
    
    return -1;
}

// Delete — Mark as DELETED
void deleteOA(OpenAddressHashTable* ht, int key) {
    int index = key % TABLE_SIZE;
    int startIndex = index;
    
    do {
        if (ht->keys[index] == EMPTY) return;
        if (ht->keys[index] == key) {
            ht->keys[index] = DELETED;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);
}
```

### Other Probing Methods

```c
// Quadratic Probing
index = (hash + i*i) % TABLE_SIZE

// Double Hashing
index = (hash1 + i * hash2) % TABLE_SIZE
where hash2(key) = PRIME - (key % PRIME)
```

---

## 4️⃣ Load Factor & Resizing

**Load Factor (α)** = n / m (elements / table size)

```c
// When α > 0.7, resize (double and rehash all elements)
void resize(HashTable* ht) {
    int oldSize = ht->size;
    Node** oldBuckets = ht->buckets;
    
    ht->size = oldSize * 2;
    ht->buckets = (Node**)calloc(ht->size, sizeof(Node*));
    
    // Rehash all elements
    for (int i = 0; i < oldSize; i++) {
        Node* current = oldBuckets[i];
        while (current) {
            insert(ht, current->key, current->value);
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(oldBuckets);
}
```

---

## 5️⃣ Interview Problems

### Problem 1: Two Sum
```c
// Find two numbers that add up to target
int* twoSum(int nums[], int n, int target) {
    HashTable ht;
    initHashTable(&ht);
    
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        int index = search(&ht, complement);
        
        if (index != -1) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = index;
            result[1] = i;
            return result;
        }
        
        insert(&ht, nums[i], i);
    }
    return NULL;
}
// Time: O(n), Space: O(n)
```

### Problem 2: Group Anagrams
```c
// Group words that are anagrams
void groupAnagrams(char* words[], int n) {
    HashTable ht;
    initHashTable(&ht);
    
    for (int i = 0; i < n; i++) {
        // Create sorted key
        char* sorted = strdup(words[i]);
        qsort(sorted, strlen(sorted), sizeof(char), compareChar);
        
        // Get or create group
        List* group = search(&ht, sorted);
        if (group == NULL) {
            group = createList();
            insert(&ht, sorted, group);
        }
        addToList(group, words[i]);
    }
}

// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
// Output: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
```

### Problem 3: Longest Consecutive Sequence
```c
// Find longest consecutive sequence in unsorted array
int longestConsecutive(int nums[], int n) {
    HashTable ht;
    initHashTable(&ht);
    
    // Add all numbers to hash table
    for (int i = 0; i < n; i++) {
        insert(&ht, nums[i], 1);
    }
    
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        // Only start counting from sequence beginning
        if (search(&ht, nums[i] - 1) == -1) {
            int currentNum = nums[i];
            int currentLength = 1;
            
            while (search(&ht, currentNum + 1) != -1) {
                currentNum++;
                currentLength++;
            }
            
            maxLength = (currentLength > maxLength) ? 
                        currentLength : maxLength;
        }
    }
    
    return maxLength;
}
// Time: O(n), Space: O(n)
```

### Problem 4: First Non-Repeating Character
```c
char firstUniqChar(char* s) {
    int freq[256] = {0};
    
    // Count frequencies
    for (int i = 0; s[i]; i++) {
        freq[s[i]]++;
    }
    
    // Find first with frequency 1
    for (int i = 0; s[i]; i++) {
        if (freq[s[i]] == 1) {
            return s[i];
        }
    }
    
    return '\0';  // None found
}
```

---

## 🧪 Practice Exercises

### Exercise 1: LRU Cache
Implement LRU cache with O(1) get and O(1) put

**Hint:** Hash table + doubly linked list

### Exercise 2: Valid Sudoku
Check if 9×9 Sudoku board is valid

**Hint:** Use hash sets for rows, columns, boxes

### Exercise 3: Subarray Sum Equals K
Count subarrays with sum = k

**Hint:** Prefix sum + hash table

---

## 🎯 Interview Tips

✓ **Default choice:** Chaining for simplicity  
✓ **Space-critical:** Open addressing saves pointers  
✓ **Load factor:** Keep α < 0.7 for good performance  
✓ **C standard:** No built-in hash table (use library or implement)  
✓ **Common pattern:** Frequency counting, deduplication, caching  

---

## 📚 Key Takeaways

- Hashing: O(1) average search, insert, delete
- Hash function: Maps keys to indices uniformly
- Collisions: Chaining (linked lists) or open addressing (probing)
- Load factor: n/m ratio, resize when > 0.7
- Trade-offs: Fast but no ordering, space overhead

---

**Next:** Day 14 - Tries (prefix trees for string operations)
