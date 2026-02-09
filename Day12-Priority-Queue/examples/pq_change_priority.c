/*
Overview:
- Updates priority of an element.
Approach:
- Modify and bubble up/down as needed.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int heap_pri[]={9,7,4}; heap_pri[2]=10; printf("%d\n", heap_pri[2]); return 0; }
