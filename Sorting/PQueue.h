#ifndef MY_HEAP_H
#define MY_HEAP_H
#include <iostream>
#include<vector>
#include "SortAlgorithms.h"

using namespace std;

/*
 * Time Complexity O(nlogn) in Average Case O(n^2) in worst case
 * Un Stable Sorting algorithm
 */

template <class T>
class PQueue : public SortAlgo<T> 
{
    vector<T> PQ;
    int N;
    bool (*compareTo) (T &a, T &b);

    void swim(int k) {
            while(k > 1 && SortAlgo<T>::less(PQ[k/2], PQ[k], compareTo)) {
                  SortAlgo<T>::exch(PQ[k/2], PQ[k]);
                  k = k/2;
            }
      }
      
    void sink(int k) {
            while (2*k <= N){
               int j = 2*k;
               if (j < N && SortAlgo<T>::less(PQ[j], PQ[j+1], compareTo)) j++;
               if (!SortAlgo<T>::less(PQ[k], PQ[j], compareTo)) {
                   break;
               }
               SortAlgo<T>::exch(PQ[k], PQ[j]);
               k = j;
            }
    }

    public:

      PQueue(int sz, bool (*compareTo) (T &a, T &b)) {
          N = 0;
          PQ.reserve(sz+1);
          this->compareTo = compareTo;
      }

      PQueue(int sz) {
          N = 0;
          PQ.reserve(sz+1);
          this->compareTo = NULL;
      }

      bool isEmpty() { 
          return N == 0;
      }    

      int size() { 
          return N; 
      }

      void insert(T v) {
          PQ[++N] = v;
          swim(N);

      }

      T getMin() {
         return PQ[1];
      }

      T getMax() {
         return PQ[1];
      }

      T delRoot() {
         T top = PQ[1];
         SortAlgo<T>::exch(PQ[1],PQ[N--]);
         sink(1);
         return top;
      }

      void deleteNode(int i) {
        T itm = PQ[i];
     
        SortAlgo<T>::exch(PQ[i],PQ[N--]);

        if (i != 1 && SortAlgo<T>::less(PQ[i/2], PQ[i], compareTo)) {
            swim(i);
        } else {
            sink(i);
        }
      }
     
      int search(T key, int i) {
          if (size() == 0 || i > N) {
              return 0;
          }

          if (PQ[i] == key) {
              return i;
          }

          int lft = search(key , 2 * i);
          int rgt = search(key , 2 * i + 1);
          if (lft) {
              return lft;
          } else {
              return rgt;
          }
      }

      void show() {
          for (int i =1; i <= N; i++) {
              cout << PQ[i] << " ";
          }
          cout << endl;
      }

};

template <typename P>
static bool minHeapify(P &a , P &b) {
    return a > b;
}

template <typename P>
static bool maxHeapify(P &a , P &b) {
    return a < b;
}

/*
int main () {

    PQueue<char> cPQ(10,compareToGt);

    cPQ.insert('P');
    cPQ.insert('Q');
    cPQ.insert('E');
    cout << "top-> "<<cPQ.delRoot() << endl;
    cPQ.insert('X');
    cPQ.insert('A');
    cPQ.insert('M');
    cout << "top-> "<<cPQ.delRoot() << endl;
    cPQ.insert('P');
    cPQ.insert('L');
    cPQ.insert('E');
    cout << "top-> " << cPQ.delRoot() << endl;
    cout << "Size: " << cPQ.size() << endl;
    return 0;
    
}*/

#endif
