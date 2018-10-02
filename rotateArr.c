#include <stdio.h>










void rotate_exspace(int* nums, int numsSize, int k) {
    int i,j=0;
    int tmp[numsSize];
    
    if (numsSize == 1)
        return;
    
    if (k > numsSize ) {
        k = k-numsSize;
    }
    
    
    for (i = numsSize-k; i < numsSize; i++) {
        tmp[j++] = nums[i];
    }
    
    for (i = 0 ; i < numsSize-k; i++) {
        tmp[j++] = nums[i];
    }
    
    for (i = 0 ; i < numsSize ; i++) {
        nums[i] = tmp[i];
    }
    
}


void rotate_exnk(int* nums, int numsSize, int k) {
    int i = 0,j=0,tmp;
    
    if (numsSize == 1 || numsSize == k )
        return;

    if (k > numsSize ) {
        k = k-numsSize;
    }
     
    while (k) {
        for (i = 1 ; i < numsSize; i++) {    
            tmp = nums[i];
            nums[i] = nums[0];
            nums[0] = tmp;
        }
        k--;
    }
    
}


void rotate (int* nums, int numsSize, int k) {
    int i = 0;

    if (numsSize == 1 || numsSize == k )
        return;

    if (k > numsSize ) {
        k = k-numsSize;
    }
    
    reverse(nums,0,numsSize-1);

    reverse(nums,0,k-1);

    reverse(nums,k,numsSize-1);
}
void reverse (int *arr, int start, int end) {

    int tmp = 0;
    while (start < end) {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;          
    }
}
























