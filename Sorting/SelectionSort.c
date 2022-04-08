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
class Selection : public SortAlgo<T> {

    public:
    
     static void sort(vector<T> &data) {
         for (int i = 0; i < data.size(); i++) {
             int min = i;
             for (int j = i+1; j < data.size(); j++) {
                 if (SortAlgo<T>::less(data[j], data[min])) {
                     min =j;
                 }
             }

             SortAlgo<T>::exch(data[i],data[min]);
         }
    }

    static void sort(vector<T> &data, bool (*compareTo) (T &a, T &b)) {
         for (int i = 0; i < data.size(); i++) {
             int min = i;
             for (int j = i+1; j < data.size(); j++) {
                 if (SortAlgo<T>::less(data[j], data[min], compareTo)) {
                     min =j;
                 }
             }

             SortAlgo<T>::exch(data[i],data[min]);
         }
    }
};

static bool compareToGt(int &a , int &b) {
    return a > b;
}

int main() {
    vector<int> a = {3,1,2,5,4};
 
    Selection<int>::sort(a, compareToGt);
    Selection<int>::show(a);
    
    return 0;
}