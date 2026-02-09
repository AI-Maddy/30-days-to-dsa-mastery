/*
Overview:
- Implements bubble sort.
Approach:
- Swap adjacent out-of-order pairs.
Complexity:
- Time: O(n^2)
- Space: O(1)
*/

#include <stdio.h>

void bubble(int a[], int n){ for(int i=0;i<n-1;i++){ for(int j=0;j<n-1-i;j++){ if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; } } } }
int main(void){ int a[]={5,1,4,2}; bubble(a,4); for(int i=0;i<4;i++) printf("%d ", a[i]); printf("\n"); return 0; }
