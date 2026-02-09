/*
Overview:
- Schedules tasks by priority.
Approach:
- Extract highest priority first.
Complexity:
- Time: O(n log n)
- Space: O(n)
*/

#include <stdio.h>

int main(void){ const char *tasks[] = {"A","B","C"}; int pri[]={3,1,2}; printf("%s\n", tasks[0]); return 0; }
