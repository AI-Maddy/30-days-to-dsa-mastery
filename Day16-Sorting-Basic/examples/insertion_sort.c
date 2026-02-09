/*
Overview:
- Implements insertion sort.
Approach:
- Insert each element into sorted prefix.
Complexity:
- Time: O(n^2)
- Space: O(1)
*/

#include <stdio.h>

void insertion(int a[], int n){ for(int i=1;i<n;i++){ int key=a[i]; int j=i-1; while(j>=0 && a[j]>key){ a[j+1]=a[j]; j--; } a[j+1]=key; } }
int main(void){ int a[]={5,2,4,6,1,3}; insertion(a,6); for(int i=0;i<6;i++) printf("%d ", a[i]); printf("\n"); return 0; }
