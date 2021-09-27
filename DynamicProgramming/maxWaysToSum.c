#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int,int> nmap;

// Classic Brute Force
//c(n) = c(n-i)+c(n-2)+c(n-3)

int numWays(vector<int> &a,int N) {

   int count = 0;

   if (N < 0) {
      return 0;
   }

   if (N == 0) {
       //cout << i<< "<<>> " << a[i] << " " << N << endl;
       return 1;
   }

   //cout << i<< " " << a[i] << " " << N << endl;

   for (int i = 0; i < a.size(); i++) {
        count +=   numWays(a, N-a[i]);
   }



   return count;
}

// Using DP Memoization technique
int numWays2(vector<int> &a,int N) {

   int count = 0;

   if (N < 0) {
      return 0;
   }

   if (N == 0) {
       //cout << i<< "<<>> " << a[i] << " " << N << endl;
       return 1;
   }

   if (nmap.find(N) != nmap.end()) {
       return nmap[N];
   }

   //cout << i<< " " << a[i] << " " << N << endl;

   for (int i = 0; i < a.size(); i++) {
        count +=   numWays(a, N-a[i]);
   }

   nmap[N] = count;

   return count;
}

//Using DP Tabulation technique.

int numWays3(vector<int> &a,int N) {
    int numWaysTb[N+1];

    memset(numWaysTb,0,N+1);

    //for (int i = 0; i < )
    numWaysTb[0] = 1;
    numWaysTb[1] = 1;
    //numWaysTb[2] = 2;

    for (int k = 2; k <= N; k++) {
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            if (k-a[i] >=0) {
                c += numWaysTb[k-a[i]];
            }
        }
        numWaysTb[k] = c;
        cout << k << " --- " << numWaysTb[k] << endl;
    }

    return(numWaysTb[N]);
}

int main() {
  int arr[] = {1,3,5};
  vector<int> v(arr, arr+3);
  int N = 6;

  int cc = numWays3(v,N);

  cout << cc << endl;

}
