/*
Overview:
- Sorts array using heap sort.
Approach:
- Build max heap, then extract to end.
Complexity:
- Time: O(n log n)
- Space: O(1)
*/

#include <stdio.h>

void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }
void build(int a[], int n){ for(int i=n/2-1;i>=0;i--) heapify(a,n,i); }
void sort(int a[], int n){ build(a,n); for(int i=n-1;i>0;i--){ int t=a[0]; a[0]=a[i]; a[i]=t; heapify(a,i,0);} }
int main(void){ int a[]={4,1,7,3,8,5}; int n=6; sort(a,n); for(int i=0;i<n;i++) printf("%d ", a[i]); printf("\n"); return 0; }
