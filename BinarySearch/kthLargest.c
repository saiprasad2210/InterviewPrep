#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int lo1 = 1;
        int hi1 = n;
        int m1;
        
        int lo2 = 1;
        int hi2 = m;
        int m2;
        
        if (k == 1) {
            return min(arr1[0], arr2[0]);
        }
        
        m1 = (lo1 + hi1)/2;
        
        m2 = (lo2 + hi2)/2;
       
        
        int mid = m1 + m2;
       
        cout << m1 << "--" << m2 << "--" << mid << endl; 
        if (k == mid) {
            return max(arr1[m1-1],arr2[m2-1]);
        } else if (k < mid) {
            return kthElement(arr1,arr2,m1,m2,k);
        } else {
            return kthElement(arr1+m1 ,arr2+m2, n-m1,m-m2,k-mid);
        }
        
        
}

int main() {
    int arr1[] = {1 ,10 ,10 ,25 ,40 ,54 ,79};
    int arr2[] = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};

    cout << "Kth-->" << kthElement(arr1,arr2,7,11,15);

}
