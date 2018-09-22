/*
 * Given a sorted array, the task is to remove the duplicate elements from the array.
 *Examples:
 *
 * Input  : arr[] = {2, 2, 2, 2, 2}
 *Output : arr[] = {2}
 *        new size = 1
 *
 * Input  : arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}
 * Output : arr[] = {1, 2, 3, 4, 5}
 * new size = 5
 */

#include <iostream>
using namespace std;
int removeDuplicates(int arr[], int n) {
    
    int i = 0, j = 0;

    for (i = 0; i <= n-2 ; i++) {

        if (arr[i] != arr[i+1]) {
            arr[j++] = arr[i];  
        }
    }
   
    arr[j++] = arr[n-1];

    return j; 
}

int main () {

    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // removeDuplicates() returns new size of
    // array.
    n = removeDuplicates(arr, n);
 
    // Print updated array
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
