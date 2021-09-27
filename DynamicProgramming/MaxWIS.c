#include <iostream>
#include <vector>

using namespace std;

// Find Maximum Weighted Indipendent set in a Path Graph
int MaxWeightIndSet(vector<int> &pg, vector<int>&out) {
    int N = pg.size();
    int A[N];

    A[0] = pg[0];

    for (int i = 1; i < N; i++) {
         A[i] = max(A[i-1], (i-2 < 0) ? (0+pg[i]) : (A[i-2]+pg[i]));
    }

    for (int i = N-1; i >= 0;) {

      if (i == 0 ) {
          out.push_back(pg[0]);
          break;
      }

      if (A[i] == A[i-1]) {
          i = i-1;
      } else {
          out.push_back(pg[i]);
          i = i-2;
      }
    }

    for (auto i: out){
       cout << i << " ";
    }
    cout << endl;

    return A[N-1];
}


int main() {
  vector<int>pg,out;

  pg.push_back(10);
  pg.push_back(2);
  pg.push_back(1);
  pg.push_back(4);

  int val = MaxWeightIndSet(pg,out);
  cout << val << endl;

  vector<int>pg2;
  pg2.push_back(1);
  pg2.push_back(3);
  pg2.push_back(10);
  pg2.push_back(9);
  pg2.push_back(6);

  out.clear();

  int val2 = MaxWeightIndSet(pg2,out);
  cout << val2 << endl;

}
