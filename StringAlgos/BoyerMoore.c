#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define ALPHABHHET_RANGE 256

#define R ALPHABHHET_RANGE

class BoyerMoore {
  vector<int> right;

public:

  BoyerMoore(string txt, string pat) {
     // Set size of vector to R
     right.resize(R);

     // For charcters not in pattern set to -1
     for (int i =0; i < R; i++) {
       right[i] = -1;
     }

     // For charcters in the pattern set to i(rightmost index)
     for (int i = 0; i < pat.length(); i++) {
         int idx = pat[i];
         right[idx] = i;
     }
  }

  ~ BoyerMoore() {
    cout << "Cleanup" << endl;

  }

  int search(string &txt, string &pat) {
      int N = txt.length();
      int M = pat.length();
      int skip = 0;
      int i,j;

      cout << pat << " " << txt << endl;

      for (i = 0; i <= N-M; i += skip ) {
           skip = 0;

           for (j = M-1; j >= 0; j--) {
                if (txt[i+j] != pat[j]) {
                    skip = max(1, j-right[txt[i+j]]);
                    break;
                }
           }

           // Pattern Matched
           if (skip == 0) {
               return i;
           }
      }

      return -1;
  }

};

int main (int arg, char *argv[]) {
    string pat,txt;

    pat = argv[2];
    txt = argv[1];

    cout << pat << " " << txt << endl;

    BoyerMoore *k = new BoyerMoore(txt,pat);

    int idx = k->search(txt,pat);
    cout << idx << endl;

    if (idx >= 0) {
        cout << "Pattern found at " << idx << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    delete k;
}
