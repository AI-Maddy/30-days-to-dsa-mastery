/*
Overview:
- Finds first and last occurrence of target.
Approach:
- Use modified binary search twice.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int first(const int a[],int n,int t){ int l=0,r=n-1,ans=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]>=t){ if(a[m]==t) ans=m; r=m-1;} else l=m+1; } return ans; }
int last(const int a[],int n,int t){ int l=0,r=n-1,ans=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]<=t){ if(a[m]==t) ans=m; l=m+1;} else r=m-1; } return ans; }
int main(void){ int a[]={1,2,2,2,3}; printf("%d %d\n", first(a,5,2), last(a,5,2)); return 0; }
