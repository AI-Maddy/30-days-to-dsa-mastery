/*
Overview:
- Performs linear search in an array.
Approach:
- Scan each element until target is found.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={3,1,4}; int t=4; int idx=-1; for(int i=0;i<3;i++) if(a[i]==t) idx=i; printf("%d\n", idx); return 0; }
