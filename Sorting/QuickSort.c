#include <iostream>
#include<vector>
#include "SortAlgorithms.h"

using namespace std;

/*
 * Time Complexity O(nlogn) in Average Case O(n^2) in worst case
 * Un Stable Sorting algorithm
 */

template <class T>
class Quick : public SortAlgo<T> 
{

    public:

    static void sort(vector<T> &data) {
          sort(data,0,data.size()-1);
    }

    static void sort(vector<T> &a,  int lo, int hi) {
         if (hi <= lo) {
             return;
         }

         int pv = partition(a,lo,hi);
         sort(a,  0,    pv-1);
         sort(a,  pv+1, hi);
    }

    
    static int partition(vector<T> &a, int lo, int hi) {
        int pv = lo;

        int i = pv + 1;
      

        for (int j = pv+1; j < a.size(); j++ ) {
             if (SortAlgo<T>::less(a[j],a[pv])) {
                 SortAlgo<T>::exch(a[j],a[i]);
                 i++;
             }
        }

        SortAlgo<T>::exch(a[pv],a[i-1]);

        return i-1;
    }


    

};

int main() {
    vector<int> a = {3,1,2,5,4};
 
    Quick<int>::sort(a);
    Quick<int>::show(a);

     vector<float> b = {1.1,3.1,0.2,0,1.8};
     Quick<float>::sort(b);
     Quick<float>::show(b);

     vector<char> str = {'s','h','e','l','l','s','o','r','t', 'e', 'x','a', 'm', 'p', 'l', 'e'};
     Quick<char>::sort(str);
     Quick<char>::show(str);
    
    return 0;
}
