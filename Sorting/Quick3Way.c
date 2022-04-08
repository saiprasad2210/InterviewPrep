#include <iostream>
#include<vector>
#include "SortAlgorithms.h"

using namespace std;

/*
 * Time Complexity O(nlogn) in Average Case O(n^2) in worst case
 * Un Stable Sorting algorithm
 * Performs well with duplicates.
 */

template <class T>
class Quick3Way : public SortAlgo<T> 
{
    public:

    static void sort(vector<T> &data) {
          sort(data,0,data.size()-1);
    }

    static void sort(vector<T> &a,  int lo, int hi) {
           if (hi <= lo) {
               return;
           }

           int lt = lo;
           int gt = hi;
           int i = lo;
           T pv = a[lo]; 

           // 3way partion
           while (i <= gt) {
               if (SortAlgo<T>::less(a[i],pv)) {          // a[i] < pv
                   SortAlgo<T>::exch(a[i],a[lt]);
                   lt++; 
               } else if (SortAlgo<T>::less(pv, a[i])) {  // a[i] > pv
                   SortAlgo<T>::exch(a[i],a[gt]);
                   gt--;
               } else { 
                   i++;                                   // a[i] == pv
               }
           }

           sort(a, lo,   lt-1);
           sort(a, gt+1, hi);
    }
};

int main() {
    vector<int> a = {3,1,2,5,4};
 
    Quick3Way<int>::sort(a);
    Quick3Way<int>::show(a);

     vector<float> b = {1.1,3.1,0.2,0,1.8};
     Quick3Way<float>::sort(b);
     Quick3Way<float>::show(b);

     vector<char> str = {'s','h','e','l','l','s','o','r','t', 'e', 'x','a', 'm', 'p', 'l', 'e'};
     Quick3Way<char>::sort(str);
     Quick3Way<char>::show(str);
    
    return 0;
}
