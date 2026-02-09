/*
Overview:
- Recursive binary search on a sorted array.
Approach:
- Split range by mid and recurse on the valid half.
Complexity:
- Time: O(log n)
- Space: O(log n)
*/

#include <stdio.h>

int bsearch_rec(const int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return bsearch_rec(arr, mid + 1, right, target);
    return bsearch_rec(arr, left, mid - 1, target);
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9};
    printf("%d\n", bsearch_rec(arr, 0, 4, 7));
    return 0;
}
