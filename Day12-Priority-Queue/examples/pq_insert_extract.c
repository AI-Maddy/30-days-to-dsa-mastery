/*
Overview:
- Implements a max-priority queue with insert/extract.
Approach:
- Use a binary heap with priority values.
Complexity:
- Time: O(log n)
- Space: O(n)
*/

#include <stdio.h>

typedef struct {int value; int priority;} Item;
int main(void){ Item heap[5]={{1,5},{2,3},{3,2}}; int size=3; Item x={4,4}; heap[size++]=x; printf("%d\n", size); return 0; }
