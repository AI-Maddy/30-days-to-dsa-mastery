# Day 06 — Stacks

## 🎯 Mastery Goals
- Understand LIFO (Last In, First Out) principle
- Implement stack using array and linked list
- Master stack applications: parentheses matching, expression evaluation, backtracking
- Recognize when stack is the optimal data structure
- Handle monotonic stack problems

---

## 1️⃣ What is a Stack?

A **stack** is a linear data structure following **LIFO** principle: last element added is first removed.

```text
     Top ┌───┐
         │ 3 │ ← pop/push operations happen here
         ├───┤
         │ 2 │
         ├───┤
  Bottom │ 1 │
         └───┘
```

### Core Operations
- **push(x)** — Add element to top: O(1)
- **pop()** — Remove top element: O(1)
- **peek()/top()** — View top element: O(1)
- **isEmpty()** — Check if empty: O(1)

---

## 2️⃣ Implementation: Array-Based

```c
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}
```

---

## 3️⃣ Implementation: Linked List-Based

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}
```

---

## 4️⃣ Classic Stack Applications

### Application 1: Balanced Parentheses
```c
// Check if brackets are balanced: "({[]})" → valid
bool isBalanced(char* expr) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        
        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        }
        // Check closing brackets
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)) return false;
            
            char top = pop(&s);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    
    return isEmpty(&s);
}
```

### Application 2: Evaluate Postfix Expression
```c
// Expression: "23+5*" → (2+3)*5 = 25
int evaluatePostfix(char* expr) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        
        // If digit, push to stack
        if (isdigit(c)) {
            push(&s, c - '0');
        }
        // If operator, pop two operands
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            
            switch (c) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }
    
    return pop(&s);
}
```

### Application 3: Next Greater Element
```c
// Find next greater element for each array element
// arr = [4, 5, 2, 10] → result = [5, 10, 10, -1]
void nextGreaterElement(int arr[], int n, int result[]) {
    Stack s;
    initStack(&s);
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller elements
        while (!isEmpty(&s) && peek(&s) <= arr[i]) {
            pop(&s);
        }
        
        // If stack empty, no greater element
        result[i] = isEmpty(&s) ? -1 : peek(&s);
        
        // Push current element
        push(&s, arr[i]);
    }
}
```

---

## 5️⃣ Advanced: Monotonic Stack

A monotonic stack maintains elements in increasing or decreasing order.

**Pattern:** Useful for "next greater/smaller" problems

```c
// Stock Span Problem: days since last higher price
// stocks = [100, 80, 60, 70, 60, 75, 85]
// span   = [  1,  1,  1,  2,  1,  4,  6]

void calculateSpan(int price[], int n, int span[]) {
    Stack s;  // Stores indices
    initStack(&s);
    
    span[0] = 1;
    push(&s, 0);
    
    for (int i = 1; i < n; i++) {
        // Pop elements smaller than current price
        while (!isEmpty(&s) && price[peek(&s)] <= price[i]) {
            pop(&s);
        }
        
        // Calculate span
        span[i] = isEmpty(&s) ? (i + 1) : (i - peek(&s));
        
        push(&s, i);
    }
}
```

---

## 🧪 Practice Exercises

### Exercise 1: Min Stack
Design a stack supporting push, pop, top, and getMin in O(1)

**Hint:** Use auxiliary stack to track minimums

### Exercise 2: Largest Rectangle in Histogram
Given histogram heights, find largest rectangular area

### Exercise 3: Implement Queue using 2 Stacks

---

## 🎯 Interview Tips

✓ **Stack vs Queue:** LIFO vs FIFO  
✓ **Stack indicators:** Parentheses, undo/redo, DFS, backtracking  
✓ **Monotonic stack:** "Next greater/smaller" problems  
✓ **Edge cases:** Empty stack, overflow  

---

## 📚 Key Takeaways

- Stack: LIFO, O(1) operations
- Applications: balanced parentheses, expression evaluation, backtracking
- Monotonic stacks solve next greater/smaller efficiently
- Function call stack uses stack internally

---

**Next:** Day 07 - Queues (FIFO data structure)
