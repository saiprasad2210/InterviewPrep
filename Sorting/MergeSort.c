#include <iostream>
#include<vector>
#include "SortAlgorithms.h"

using namespace std;

/*
 * Time Complexity O(n^2/2)
 * O(n) swaps
 * Even for perfectly sorted array no imptovement in time complexity.
 */

template <class T>
class Merge : public SortAlgo<T> {

    public:
    
     static void sort(vector<T> &data) {
          vector<T> aux(data.size());

          sort(data,aux,0,data.size()-1);
     }

     static void sort(vector<T> &a, vector<T> &aux, int lo, int hi) {
         if (hi <= lo) {
             return;
         }

         int mid = lo + (hi - lo)/2;
         sort(a,aux,lo,mid);
         sort(a,aux,mid+1,hi);
         merge(a,aux,lo,mid,hi);
     }


     static void merge(vector<T> &a, vector<T> &aux, int lo, int mid, int hi) {

        
         for (int t = lo; t <= hi; t++) {
             aux[t] = a[t];
         }

         int i = lo;
         int j = mid+1;

         for (int k = lo; k <= hi; k++) {
             if      (i > mid)                        a[k] = aux[j++];
             else if (j > hi)                         a[k] = aux[i++];
             else if (SortAlgo<T>::less(a[j],a[i]))   a[k] = aux[j++];
             else                                     a[k] = aux[i++];
         }
     }

     static void sort(vector<T> &data, bool (*compareTo) (T &a, T &b)) {
          vector<T> aux(data.size());

          sort(data,aux,0,data.size()-1,compareTo);
     }

     static void sort(vector<T> &a, vector<T> &aux, int lo, int hi, bool (*compareTo) (T &a, T &b)) {
         if (hi <= lo) {
             return;
         }

         int mid = lo + (hi - lo)/2;
         sort(a,aux,lo,mid,compareTo);
         sort(a,aux,mid+1,hi,compareTo);
         merge(a,aux,lo,mid,hi,compareTo);
     }


     static void merge(vector<T> &a, vector<T> &aux, int lo, int mid, int hi, bool (*compareTo) (T &a, T &b)) {

        
         for (int t = lo; t <= hi; t++) {
             aux[t] = a[t];
         }

         int i = lo;
         int j = mid+1;

         for (int k = lo; k <= hi; k++) {
             if      (i > mid)                                   a[k] = aux[j++];
             else if (j > hi)                                    a[k] = aux[i++];
             else if (SortAlgo<T>::less(a[j],a[i], compareTo))   a[k] = aux[j++];
             else                                                a[k] = aux[i++];
         }
     }
};

static bool compareToGt(int &a , int &b) {
    return a > b;
}

int main() {
    vector<int> a = {3,1,2,5,4};
 
     Merge<int>::sort(a,compareToGt);
     Merge<int>::show(a);

     vector<float> b = {1.1,3.1,0.2,0,1.8};
     Merge<float>::sort(b);
     Merge<float>::show(b);

     vector<char> str = {'s','h','e','l','l','s','o','r','t', 'e', 'x','a', 'm', 'p', 'l', 'e'};
     Merge<char>::sort(str);
     Merge<char>::show(str);
    
    return 0;
}