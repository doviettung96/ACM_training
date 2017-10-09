#include <stdio.h>
#include "segment_tree.h"

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = construct(arr, n);
 
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d¥n", 
            getSum(st, n, 1, 3));
 
    // Update: set arr[1] = 10 and update corresponding 
    // segment tree nodes
    update(arr, n, st, 1, 10);
 
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d¥n",
             getSum(st, n, 1, 3));
    return 0;
}