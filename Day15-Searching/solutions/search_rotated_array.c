/*
Overview:
- Searches in rotated sorted array.
Approach:
- Use binary search with pivot logic.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={4,5,6,7,0,1,2}; int l=0,r=6,t=0,idx=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t){ idx=m; break; } if(a[l]<=a[m]){ if(a[l]<=t && t<a[m]) r=m-1; else l=m+1; } else { if(a[m]<t && t<=a[r]) l=m+1; else r=m-1; } } printf("%d\n", idx); return 0; }
