/*
Overview:
- Implements selection sort.
Approach:
- Select minimum each pass and swap.
Complexity:
- Time: O(n^2)
- Space: O(1)
*/

#include <stdio.h>

void selection(int a[], int n){ for(int i=0;i<n-1;i++){ int m=i; for(int j=i+1;j<n;j++) if(a[j]<a[m]) m=j; int t=a[i]; a[i]=a[m]; a[m]=t; } }
int main(void){ int a[]={64,25,12,22,11}; selection(a,5); for(int i=0;i<5;i++) printf("%d ", a[i]); printf("\n"); return 0; }
