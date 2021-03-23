#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SuffixArray {
      vector<string> suffix;
      int N;

public:

     SuffixArray(string str) {
         N = str.length();

         // Create suffix array
         suffix.resize(N);
         for (int i = 0; i < N; i++) {
             suffix[i] = str.substr(i,string::npos);
         }

         // Sort
         std::sort(suffix.begin(),suffix.end());

     } 

     int length() {
        return N;
     }

     
     string select(int i) {
         return suffix[i];
     }

     // Index in original string
     int index(int i) {
         return N-suffix[i].length();
     }

     // Longest common prefix
     int lcp(int i) {
         int j;
         int len = min(suffix[i].length(), suffix[i-1].length());
         for (j = 0; j < len; j++) {
              if (suffix[i].at(j) != suffix[i-1].at(j)) {
                  break;
              }
         }

         return j;
     }

     void display() {
         for (int i = 0; i < N; i++) {
             cout << suffix[i] << endl;
         }

     }

};

// Longest repeated pattern in a txt string
string lrs(string txt) {
    // Build a suffix array from the given txt
    string s;
    SuffixArray SA = SuffixArray(txt); 
       

    for (int i = 1 ; i < SA.length(); i++) {
         
         int len = SA.lcp(i);
         if ( len > s.size()) {
             s = SA.select(i).substr(0,len);
         }
    }

    return s;

}
int main(int argc , char *argv[]) {
    cout << lrs(argv[1]) << endl;

}