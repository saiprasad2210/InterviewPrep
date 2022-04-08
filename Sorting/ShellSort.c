
#include <iostream>
#include<vector>
#include "SortAlgorithms.h"

using namespace std;


/*
 * Time Complexity O(n^2/4) 
 * Twice as fast as Selection, works fast on fully sorted or partially sorted arrays
 * O(n^2) swaps (when input is descending order)
 * Even for perfectly sorted array no imptovement in time complexity.
 */

// derived class
template <class T>
class ShellSort : public SortAlgo<T> {
 
   public:

    static void sort(vector<T> &data) {
        int N = data.size();
        int h = 0;

        while (h < N/3) {
            h = 3 * h + 1;
        }
        
        while (h > 0) {
            for (int i =h; i < N; i++) {
                for (int j = i; j >0; j = j-h) {
                    if (SortAlgo<T>::less(data[j],data[j-h])) {
                        SortAlgo<T>::exch(data[j],data[j-h]);
                    }
                }
            }

            h = h/3;
        }
        
   }

   static void sort(vector<T> &data, bool (*compareTo) (T &a, T &b)) {
        int N = data.size();
        int h = 0;

        while (h < N/3) {
            h = 3 * h + 1;
        }
        
        while (h > 0) {
            for (int i =h; i < N; i++) {
                for (int j = i; j >0; j = j-h) {
                    if (SortAlgo<T>::less(data[j],data[j-h], compareTo)) {
                        SortAlgo<T>::exch(data[j],data[j-h]);
                    }
                }
            }

            h = h/3;
        }
   }

};

static bool compareToGt(int &a , int &b) {
    return a > b;
}

int main() {
    vector<int> a = {3,1,2,5,4};
 
    ShellSort<int>::sort(a,compareToGt);
    ShellSort<int>::show(a);

     vector<float> b = {1.1,3.1,0.2,0,1.8};
     ShellSort<float>::sort(b);
     ShellSort<float>::show(b);

     vector<char> str = {'s','h','e','l','l','s','o','r','t', 'e', 'x','a', 'm', 'p', 'l', 'e'};
     ShellSort<char>::sort(str);
     ShellSort<char>::show(str);
    
    return 0;
}