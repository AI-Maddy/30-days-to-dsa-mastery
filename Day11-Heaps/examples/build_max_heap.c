/*
Overview:
- Builds a max-heap from an array.
Approach:
- Heapify from last non-leaf to root.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }
void build(int a[], int n){ for(int i=n/2-1;i>=0;i--) heapify(a,n,i); }
int main(void){ int a[]={3,9,2,1,4,5}; int n=6; build(a,n); printf("%d\n", a[0]); return 0; }
