#include <iostream>
#include <vector>

using namespace std;

// function to find out the minimum penalty
void getMinimumPenalty(string x, string y, int pxy, int pgap) {
     int m = x.size();
     int n = y.size();

     int dp[m+1][n+1];;

     for (int i = 0; i <= m; i++) {
          dp[i][0] = i * pgap;
     }

     for (int j = 0; j <= n ; j++) {
          dp[0][j] = j * pgap;
     }


     for (int i = 1; i <= m; i++) {
          for (int j = 1; j <= n; j++) {
               int p = 0;

               if (x[i-1] == y[j-1]) {
                   p = 0;
               } else {
                   p = pxy;
               }

               int a =  p  + dp[i-1][j-1];
               int b =  pgap + dp[i-1][j];
               int c =  pgap + dp[i][j-1];
               dp[i][j] = min(min(a,b),c);
          }
    }

    int i = m;
    int j = n;
    vector<char> x_s;
    vector<char> y_s;

    while(i > 0 && j > 0) {
         if (dp[i][j] == dp[i-1][j-1] ||
             dp[i][j] == pxy + dp[i-1][j-1]) {
             x_s.push_back(x[i-1]);
             y_s.push_back(y[j-1]);
             i--;
             j--;
         } else if (dp[i][j] == pgap + dp[i-1][j]) {
             x_s.push_back(x[i-1]);
             y_s.push_back('-');
             i--;
         } else {
             x_s.push_back('-');
             y_s.push_back(y[j-1]);
             j--;
         }
    }


    while (i > 0 ) {
        x_s.push_back(x[i-1]);
        y_s.push_back('-');
        i--;
    }

    while (j > 0 ) {
        x_s.push_back('-');
        y_s.push_back(y[j-1]);
        j--;
    }

    for(int l = x_s.size()-1; l >= 0; l--) {
        cout << x_s[l];
    }

    cout << endl;

    for(int l = y_s.size()-1; l >= 0; l--) {
        cout << y_s[l];
    }

    cout << endl;

    cout << dp[m][n] << endl;
}

// Driver code
int main(){
  // input strings
      string gene1 = "AGGGCT";
      string gene2 = "AGGCA";

      // initialsing penalties of different types
      int misMatchPenalty = 3;
      int gapPenalty = 2;

      // calling the function to calculate the result
      getMinimumPenalty(gene1, gene2,
          misMatchPenalty, gapPenalty);
      return 0;
}
