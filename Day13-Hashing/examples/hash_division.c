/*
Overview:
- Computes hash index with division method.
Approach:
- Use key % table_size.
Complexity:
- Time: O(1)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int key=37, size=10; printf("%d\n", key%size); return 0; }
