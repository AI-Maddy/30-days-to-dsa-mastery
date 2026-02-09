/*
Overview:
- Counts swaps performed by bubble sort.
Approach:
- Increment count whenever a swap occurs.
Complexity:
- Time: O(n^2)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={3,2,1}; int n=3; int swaps=0; for(int i=0;i<n-1;i++){ for(int j=0;j<n-1-i;j++){ if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; swaps++; } } } printf("%d\n", swaps); return 0; }
