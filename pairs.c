#include <iostream>
using namespace std;

#define MAX 100000
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;  // Initialize count
 
    // Initialize empty hashmap.
    bool hashmap[MAX] = {false};
 
    // Insert array elements to hashmap
    for (int i = 0; i < n; i++)
        hashmap[arr[i]] = true;
 
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x - k >= 0 && hashmap[x - k])
            count++;
        if (x + k < MAX && hashmap[x + k])
            count++;
        hashmap[x] = false;
    }
    return count;
}

int countParisSorted (int *a, int k, int n) {
    
    int i, count = 0, l = 0, r = n-1, diff;

    if (a[r] - a[l] < k )
        return 0;

    while (r >= 0 && l >= 0) {
       
       diff = a[r] -a[l];

       if (diff == k ) {
          
          count++;
          r--;
          //l++;
       } else if (diff > k) {
          l++;
       } else {
          l--;
       }
                
    }

    return count;

}


main (int argc, char *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(a)/sizeof(int);

    cout << "Number of pairs with difference of " << 1 << " is " <<  countParisSorted(a, 1, n);   
}

      
