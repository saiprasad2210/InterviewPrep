#include<iostream>

using namespace std;

void printUnion (int *arr1, int *arr2, int m, int n) {

    int i = 0 , j = 0, k = 0;

    for (i = 0, j = 0; i < m && j < n; ) {

         if (arr1[i] < arr2[j]) {
             cout <<  arr1[i] << " " ;
             i++;
         } else if (arr1[i] == arr2[j]) {

             cout <<  arr1[i] << " ";
             i++; j++;
         } else {
             cout <<  arr2[j] << " ";
             j++;
         }
    }

    if ( i == m) {
       for (k = j ; k < n; k++) 
          cout <<  arr2[k] << " ";
    } else if ( j == n) {
       for (k = i ; k < m; k++)
          cout << arr1[k] << " ";
    }

}

void printIntersection (int *arr1, int *arr2, int m, int n) {

    int i = 0 , j = 0, k = 0;

    for (i = 0, j = 0; i < m && j < n; ) {

         if (arr1[i] < arr2[j]) {
             i++;
         } else if (arr1[i] == arr2[j]) {

             cout <<  arr1[i] << " ";
             i++; j++;
         } else {
             j++;
         }
    }



} 

int main () {

  int arr1[] = {1, 2, 4, 5, 6};
  int arr2[] = {2, 3, 5, 7};
  int m = sizeof(arr1)/sizeof(arr1[0]);
  int n = sizeof(arr2)/sizeof(arr2[0]);
   
  // Function calling
  //printUnion(arr1, arr2, m, n);
  //
  printIntersection(arr1, arr2, m, n);
}
