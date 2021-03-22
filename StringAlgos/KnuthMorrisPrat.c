#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define ALPHABHHET_RANGE 256

#define R ALPHABHHET_RANGE


class KMP {
     int  *dfa;
     int M;
     int N;

     void build_dfa(string &pat) {
          int X = 0;
          int idx = pat[0];

          *(dfa + idx * M + 0 ) = 1;
          //dfa[idx][0] = 1;

          for (int j = 1; j < M; j ++) {
               // Copy entries from restart state X
               for (int c = 0; c < R; c++) {
                    //dfa[c][j] = dfa[c][X];
                      *(dfa + c * M + j ) = *(dfa + c * M + X );
               }

               // matching transition
               //dfa[pat[j]][j] = j+1;
               *(dfa + (int)pat[j] * M + j ) = j+1;

               // Update restart state X
               //X = dfa[pat[j]][X];
               X = *(dfa + (int)pat[j] * M + X );
          }
     }

   public:


     KMP (string pat, string txt) {
          this->M = pat.size();
          this->N = txt.size();

          int *ptr  = new int[R * M];
          this->dfa =  ptr;

          memset(dfa, 0, R * M);

          build_dfa(pat);
     }

     ~ KMP () {
         cout << "Cleaning up dfa memory" << endl;
         delete[] dfa;
     }

     int search (string &pat, string &txt) {
         int j = 0;

         for (int i = 0 ; i < N; i++) {
               int idx = txt[i];
              //j = dfa[idx][j];
              j = *(dfa + idx * M + j);


              if (j == M) {
                  return i-j+1;
              }

         }
         return -1;
     }
};

class KMP2 {
     vector<vector<int> > dfa;

     int M;
     int N;

     void build_dfa(string &pat) {
          int X = 0;
          int idx = pat[0];

          //*(dfa + idx * M + 0 ) = 1;

          dfa[idx][0] = 1;


          for (int j = 1; j < M; j ++) {
               // Copy entries from restart state X
               for (int c = 0; c < R; c++) {
                    dfa[c][j] = dfa[c][X];
                      //*(dfa + c * M + j ) = *(dfa + c * M + X );
               }

               // matching transition
               dfa[pat[j]][j] = j+1;
               //*(dfa + (int)pat[j] * M + j ) = j+1;

               // Update restart state X
               X = dfa[pat[j]][X];
               //X = *(dfa + (int)pat[j] * M + X );
          }
     }

   public:


     KMP2 (string pat, string txt) {
          this->M = pat.size();
          this->N = txt.size();
          dfa.resize(R);
          for (int i = 0; i < R; i ++ ) {
               dfa[i].resize(M);
          }
          build_dfa(pat);
     }

     ~ KMP2 () {
        
     }

     int search (string &pat, string &txt) {
         int j = 0;

         for (int i = 0 ; i < N; i++) {
               int idx = txt[i];
               j = dfa[idx][j];
              //j = *(dfa + idx * M + j);


              if (j == M) {
                  return i-j+1;
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

    KMP2 *k = new KMP2(pat,txt);

    int idx = k->search(pat,txt);

    if (idx >= 0) {
        cout << "Pattern found at " << idx << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    delete k;
}
