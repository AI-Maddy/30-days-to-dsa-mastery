/*
Overview:
- Jump search in sorted array.
Approach:
- Jump by sqrt(n) blocks, then linear scan.
Complexity:
- Time: O(sqrt(n))
- Space: O(1)
*/

#include <stdio.h>
#include <math.h>

int main(void){ int a[]={1,3,5,7,9,11}; int n=6; int t=7; int step=(int)sqrt(n); int prev=0; while(a[(step<n?step:n)-1]<t){ prev=step; step+= (int)sqrt(n); if(prev>=n){ printf("-1\n"); return 0; } } int idx=-1; for(int i=prev;i<step && i<n;i++) if(a[i]==t) idx=i; printf("%d\n", idx); return 0; }
