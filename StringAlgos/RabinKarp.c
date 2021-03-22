#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define ALPHABHHET_RANGE 256



class RabinKarp {
   long RM;
   long Q;
   int R;
   int M;
   long patHash;

//Uses Horner Method
long hash(string str, int M) {
     long h = 0;
     for(int i = 0; i < M; i++) {
         h = (h * R + str[i]) % Q;
     }

     return h;
}


 public:

   RabinKarp(string txt, string pat) {
         M = pat.length();
         R = 256;
         Q = 9576890767;
         RM = 1;

         for (int i = 1; i <= M-1; i++) {
              RM = (RM * R) % Q;
         }
         patHash = hash(pat,M);
         cout << "patHash "<< patHash << endl;
   }

   int search (string txt, string pat) {

       int N = txt.length();
       long txtHash = hash(txt,M);

       if (txtHash == patHash) {
           return 0;
       }

       for(int i = M; i < N; i++) {
           //cout << "txtHash "<< txtHash << endl;
           txtHash = (txtHash + Q - RM * txt[i-M] % Q) % Q;
           txtHash = (txtHash * R + txt[i]) % Q;

           if (patHash == txtHash) {
               return i-M+1;
           }
       }

       return -1;
   }
};

int main (int arg, char *argv[]) {
    string pat,txt;

    pat = argv[2];
    txt = argv[1];

    RabinKarp *k = new RabinKarp(txt,pat);

    int idx = k->search(txt,pat);

    cout << idx << endl;

    if (idx >= 0) {
        cout << "Pattern found at " << idx << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    delete k;
}
