/*
Overview:
- Checks if parentheses are balanced.
Approach:
- Push opening brackets and match with closing brackets.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void init_stack(CharStack *s) {
    s->top = -1;
}

bool is_empty(const CharStack *s) {
    return s->top == -1;
}

void push(CharStack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(CharStack *s) {
    if (is_empty(s)) {
        return '\0';
    }
    return s->data[(s->top)--];
}

bool is_balanced(const char *expr) {
    CharStack s;
    init_stack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            char top = pop(&s);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return is_empty(&s);
}

int main(void) {
    const char *expr = "({[]})";
    printf("%s\n", is_balanced(expr) ? "balanced" : "not balanced");
    return 0;
}
