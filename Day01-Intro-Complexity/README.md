# Day 01 — Introduction to DSA & Complexity Analysis

## 🎯 Mastery Goals

- Understand what Data Structures & Algorithms (DSA) are and why they matter
- Build strong intuition for time and space complexity
- Learn to express algorithm performance using Big‑O, Big‑Theta, and Big‑Omega
- Analyze loops, nested loops, and simple recursion confidently in interviews
- Master complexity analysis patterns that appear in 90% of interview questions

---

## 1️⃣ Why DSA Matters

**Data Structures** define **how** data is stored in memory.  
**Algorithms** define **how** data is processed and manipulated.

### The Interview Lens

In technical interviews, you're evaluated on:

- ✅ **Correctness** — Does your solution work for all cases?
- ⚡ **Efficiency** — Time & Space complexity
- 💬 **Communication** — Can you explain your thought process?
- ⚖️ **Trade‑offs** — When is solution A better than solution B?

**Real Example:**  
Given an array, find two numbers that sum to a target.

- **Brute Force:** Check all pairs → O(n²)
- **Optimal:** Use hash table → O(n)

Knowing complexity analysis lets you justify why the second approach is better.

### Why Companies Care

```text
Slow Algorithm on Small Data: ✓ Works fine
Slow Algorithm on Big Data: ✗ Timeouts, crashes, costs $$$$

Amazon processes billions of transactions
Google indexes trillions of web pages
Meta handles billions of social interactions
```

Efficient algorithms = **Better user experience + Lower costs**

---

## 2️⃣ Time Complexity — Big‑O, Big‑Theta, Big‑Omega

### Big‑O (O) — Upper Bound

**Definition:** The growth rate of an algorithm in the **worst case**.

**Formal:** f(n) = O(g(n)) if ∃ constants c, n₀ such that f(n) ≤ c·g(n) for all n ≥ n₀

**Practical:** Drop constants and lower-order terms.

```c
T(n) = 3n² + 5n + 10
     = O(n²)          // Drop 5n and 10, drop constant 3
```

**Example:**

```c
for (int i = 0; i < n; i++) {           // Runs n times
    for (int j = 0; j < n; j++) {       // Runs n times for each i
        printf("%d ", i + j);           // O(1) operation
    }
}
// Total: n * n * O(1) = O(n²)
```

### Big‑Theta (Θ) — Tight Bound

Both upper AND lower bound — the algorithm grows exactly at this rate.

```c
// Merge Sort always splits and merges
// Best, Average, Worst: Θ(n log n)
```

### Big‑Omega (Ω) — Lower Bound

**Best case** scenario.

```c
// Linear search can find element at index 0
// Best case: Ω(1)
// Worst case: O(n)
```

### Interview Tip 💡

- **90% of the time, use Big‑O** (worst-case)
- Mention Θ when all cases are the same
- Mention Ω only if asked about best case

---

## 3️⃣ Common Time Complexities (Master This Table!)

| Complexity     | Name          | Example                      | n=10 | n=100 | n=1000 | When n doubles   |
|----------------|---------------|------------------------------|------|-------|--------|------------------|
| **O(1)**       | Constant      | Array access \`arr[i]\`      | 1    | 1     | 1      | Stays same       |
| **O(log n)**   | Logarithmic   | Binary search                | 3    | 7     | 10     | +1 operation     |
| **O(n)**       | Linear        | Loop through array           | 10   | 100   | 1000   | Doubles          |
| **O(n log n)** | Linearithmic  | Merge sort, Heap sort        | 30   | 664   | 10000  | > 2x             |
| **O(n²)**      | Quadratic     | Nested loops                 | 100  | 10K   | 1M     | 4x               |
| **O(n³)**      | Cubic         | Triple nested loops          | 1K   | 1M    | 1B     | 8x               |
| **O(2ⁿ)**      | Exponential   | Fibonacci (naive)            | 1K   | 2³⁰   | ∞      | Squares!         |
| **O(n!)**      | Factorial     | Generate all permutations    | 3.6M | ∞     | ∞      | Explodes         |

### Visualizing Growth

```text
Operations for different complexities (n = 1000):

O(1):        1                                          |
O(log n):    10                                         |
O(n):        1,000                                      |
O(n log n):  10,000                                     |▓
O(n²):       1,000,000                                  |▓▓▓▓▓▓▓▓▓▓▓▓
O(2ⁿ):       More than atoms in universe               |████████████
```

### Quick Recognition Guide

```c
// O(1) - Constant
int x = arr[5];

// O(log n) - Dividing/halving each iteration
while (n > 1) {
    n = n / 2;  // or n /= 2, or i *= 2
}

// O(n) - Single loop
for (int i = 0; i < n; i++) { }

// O(n log n) - Loop with divide-and-conquer
// Merge sort, Quick sort (average)

// O(n²) - Nested loops
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) { }

// O(2ⁿ) - Recursive branching (2 calls each level)
fib(n-1) + fib(n-2)
```

---

## 4️⃣ Analyzing Loops — Patterns & Tricks

### Pattern 1: Single Loop

```c
for (int i = 0; i < n; i++) {
    printf("%d ", i);  // O(1) work
}
```

⏱ **Time: O(n)**  
🧠 **Logic:** Loop runs n times, each iteration is O(1)

### Pattern 2: Nested Loops (Same Range)

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d ", i * j);  // O(1) work
    }
}
```

⏱ **Time: O(n²)**  
🧠 **Logic:** Outer runs n times, inner runs n times for each → n × n

### Pattern 3: Nested Loops (Dependent)

```c
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {  // Starts from i, not 0!
        // work
    }
}
```

⏱ **Time: O(n²)** ← Surprise! Still quadratic  
🧠 **Count iterations:**

- i=0: inner runs n times
- i=1: inner runs n-1 times
- i=2: inner runs n-2 times
- Total: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²)

### Pattern 4: Logarithmic Loop

```c
int i = 1;
while (i < n) {
    printf("%d ", i);
    i = i * 2;  // or i *= 2
}
```

⏱ **Time: O(log n)**  
🧠 **Logic:** 1 → 2 → 4 → 8 → ... → n requires log₂(n) steps

**Another example:**

```c
while (n > 1) {
    printf("%d ", n);
    n = n / 2;
}
```

⏱ **Time: O(log n)** (dividing down)

### Pattern 5: Loop with Logarithmic Inner Loop

```c
for (int i = 0; i < n; i++) {       // O(n)
    int j = 1;
    while (j < n) {                 // O(log n)
        j *= 2;
    }
}
```

⏱ **Time: O(n log n)**  
🧠 **Logic:** Outer O(n) × Inner O(log n)

### Pattern 6: Tricky — Geometric Series

```c
for (int i = 1; i < n; i *= 2) {    // O(log n) iterations
    for (int j = 0; j < i; j++) {   // i iterations
        // O(1) work
    }
}
```

⏱ **Time: O(n)** ← Surprising!  
🧠 **Logic:**

- i=1: 1 iteration
- i=2: 2 iterations
- i=4: 4 iterations
- i=8: 8 iterations
- Total: 1 + 2 + 4 + 8 + ... = 2n - 1 = O(n)

### Pattern 7: Multiple Sequential Loops

```c
for (int i = 0; i < n; i++) { }     // O(n)
for (int j = 0; j < n; j++) { }     // O(n)
for (int k = 0; k < n; k++) { }     // O(n)
```

⏱ **Time: O(n)** not O(3n)  
🧠 **Logic:** O(n) + O(n) + O(n) = O(3n) = O(n)

---

## 🔬 Example Programs (in \`examples/\`)

- \`constant_time.c\` — Demonstrates O(1)
- \`linear_time.c\` — Demonstrates O(n)
- \`quadratic_time.c\` — Demonstrates O(n²)

---

## 🧪 Exercises (in \`exercises/\`)

1. Analyze the time and space complexity
2. Write recursive functions and analyze complexity
3. Compare brute force vs optimal solutions

---

## ✅ Solutions (in \`solutions/\`)

- Detailed solutions with complexity analysis
- Step-by-step explanations

---

## 🧠 Key Takeaways

✓ **Master the complexity hierarchy:** O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) < O(n!)

✓ **Loop analysis shortcuts:**

- Single loop = O(n)
- Nested loops = multiply complexities
- Halving/doubling = O(log n)

✓ **In interviews:**

- Always state complexity
- Explain trade-offs
- Start with brute force, then optimize

---

**Tomorrow:** Apply this to Arrays — the most fundamental data structure!
