#ifndef MYPOLY_H
#define MYPOLY_H

#include <iostream>
#include<vector>

using namespace std;

template <class T>
class SortAlgo {

   public:

      static void sort(vector<T> &data);

      static bool less (T &a, T &b) {
            return a < b;
      }

      static bool less (T &a, T &b, bool (*compareTo) (T &a, T &b)) {
            
            return compareTo(a,b);
            
      }

      static void exch(T &a, T &b) {
           T tmp = a;
           a = b;
           b = tmp;
      }
      

      static void show (vector<T> &data) {
           for (auto i : data) {
                 cout << i << " ";
           }    
           cout << endl; 
      }

      static bool isSorted (vector<T> &arr) {
          for (int i = 0; i < arr.size()-1; i++) {
                if (arr[i] > arr[i+1]) {
                    return false;
                }
          }

          return true;
      } 

};

/*
// Base Class
class SortAlgo {

   public:

      static void sort(vector<int> &data);

      static bool less (int &a, int &b) {
            return a < b;
      }

      static bool less (int &a, int &b, bool (*compareTo) (int &a, int &b)) {
            return compareTo(a,b);
      }

      static void exch(int &a, int &b) {
           int tmp = a;
           a = b;
           b = tmp;
      }
      

      static void show (vector<int> &data) {
           for (auto i : data) {
                 cout << i << " ";
           }    
           cout << endl; 
      }

      static bool isSorted (vector<int> &arr) {
          for (int i = 0; i < arr.size()-1; i++) {
                if (arr[i] > arr[i+1]) {
                    return false;
                }
          }

          return true;
      } 

};*/

#endif




