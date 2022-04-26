
#ifndef _UNION_FIND_
#define _UNION_FIND_

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//
class WeightedQuickUnionUF 
{

   vector<int> id;
   vector<int> sz;
   int cnt;

public:

   WeightedQuickUnionUF(int N) {
       id.reserve(N);
       sz.reserve(N);

       for (int i = 0; i < N; i++) {
           id[i] = i;
           sz[i] = 1;
       }
 
       cnt = N;

   }
        
   bool connected(int p, int q) {
        return (find(p) == find(q));
   }

   // runs in O(logN)
   int find(int p) {
       // swim up till root is encountered.
       while(id[p] != p) {
            p = id[p];
       }
       return p;
   }

    // runs in O(logN)
  void Union(int p, int q) {

       // find roots of both the nodes
       int i = find(p);
       int j = find(q);

       if (i == j) {
           return;
       }

       // always connect smaller subtree to larger
       if (sz[i] < sz[j]) { 
           id[i] = j; 
           sz[j] += sz[i]; 
           //cout << i << " -- " << id[i] << endl; 
       } else { 
          id[j] = i; 
          sz[i] += sz[j];
          //cout << j << " -- " << id[j] << endl; 
       } 

       cnt--;
  }

  int count() {
      return cnt;
  }
   
};

#endif

/*
int main() {
    int N = 10;
    WeightedQuickUnionUF Set(10);

    Set.Union(4,3);
    Set.Union(3,8);
    Set.Union(6,5);
    Set.Union(9,4);
    Set.Union(2,1);
    Set.Union(8,9);
    Set.Union(5,0);
    Set.Union(7,2);
    Set.Union(6,1);
    Set.Union(1,0);

    cout << Set.count() << endl;
}*/

