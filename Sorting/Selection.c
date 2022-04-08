
#include <iostream>
#include<vector>
#include "SortAlgorithms.h"

using namespace std;

/*
 * Time Complexity O(nlogn) in Average Case O(n) in worst case
 * Un Stable Sorting algorithm
 */

template <class T>
class RSelect : public SortAlgo<T> 
{

    public:

    static T select(vector<T> &a, int i) {
           if (a.size() == 1) {
            return a[0];
           } 

           if (i > a.size() || i < 0) {
               return -1;
           }

           return select(a,i-1,0,a.size()-1);
    }

    static T select(vector<T> &a, int i, int lo, int hi) {

        // shuffle a

        int pv = partition(a, lo, hi);

        //cout << pv << "  " << a[pv] << endl;

        if (i == pv) {
            return a[i];
        }

        if (i < pv) {
            return select(a, i, lo, pv-1);
        } else if (i > pv) {
            return select(a, i, pv+1, hi);
        } 
               
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
 
     cout << RSelect<int>::select(a,5) << endl;


     vector<float> b = {1.1,3.1,0.2,0,1.8};
     cout << RSelect<float>::select(b,5) << endl;

     vector<char> str = {'s','h','e','l','l','s','o','r','t', 'e', 'x','a', 'm', 'p', 'l', 'e'};
     cout << RSelect<char>::select(str,16) << endl;
    
    return 0;
}
