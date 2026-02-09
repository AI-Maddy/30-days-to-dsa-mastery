/*
Overview:
- Checks if an array is sorted.
Approach:
- Verify each adjacent pair.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={1,2,3}; int ok=1; for(int i=1;i<3;i++) if(a[i-1]>a[i]) ok=0; printf("%d\n", ok); return 0; }
