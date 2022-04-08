
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
class Insertion : public SortAlgo<T> {
 
   public:

    static void sort(vector<T> &data) {
        
        for (int i = 0; i < data.size(); i++) {
            //cout << data[i] << " ";
             for (int j = i; j > 0; j--) {
                 if (SortAlgo<T>::less(data[j],data[j-1])) {
                     SortAlgo<T>::exch(data[j],data[j-1]);
                     //cout << "exch:" << data[j] << " " << data[j-1] << " ";
                 } else {
                     break;
                 }
             }
        }
   }

   static void sort(vector<T> &data, bool (*compareTo) (T &a, T &b)) {
        
        for (int i = 0; i < data.size(); i++) {
            //cout << data[i] << " ";
             for (int j = i; j > 0; j--) {
                 if (SortAlgo<T>::less(data[j],data[j-1], compareTo)) {
                     SortAlgo<T>::exch(data[j],data[j-1]);
                     //cout << "exch:" << data[j] << " " << data[j-1] << " ";
                 } else {
                     break;
                 }
             }
        }
   }

};

static bool compareToGt(int &a , int &b) {
    return a > b;
}

int main() {
    vector<int> a = {3,1,2,5,4};
 
    Insertion<int>::sort(a,compareToGt);
    Insertion<int>::show(a);

     vector<float> b = {1.1,3.1,0.2,0,1.8};
     Insertion<float>::sort(b);
     Insertion<float>::show(b);

     vector<char> str = {'s','h','e','l','l','s','o','r','t', 'e', 'x','a', 'm', 'p', 'l', 'e'};
     Insertion<char>::sort(str);
     Insertion<char>::show(str);
    
    return 0;
}