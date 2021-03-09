#include <iostream>
#include <string.h>
using namespace std;

int pmach_naive(char *pat, char *txt);

// When all charecters of Pattern are different
int pmach_naive2(char *pat, char *txt) {
    int m, n, i,j;

    m = strlen(pat);
    n = strlen(txt);

    for (i = 0; i <= n-m; ) {
        
         for (j = 0; j < m;j++) {
              if (pat[j] != txt[i+j]) {
                  break;
              } 
         }

         if (j == m) {
             return i;
         } 

         if (j > 0) {
            i = i+j;
         }
         else 
         {
            i++;
         }
         
    }
        
    return -1;
}

int pmach_naive(char *pat, char *txt) {
    int m, n, i,j;

    m = strlen(pat);
    n = strlen(txt);

    for (i = 0; i <= n-m; i++) {
        
         for (j = 0; j < m;j++) {
              if (pat[j] != txt[i+j]) {
                  break;
              } 
         }

         if (j == m) {
             return i;
         } 
    }
        
    return -1;
}

int main(int arc, char *argv[]) {
    char txt[] = "ABABABABABC", pat[]="ABC";
    int a;

    a = pmach_naive2(pat, txt);
    if (a >= 0) {
          cout << "Match Found at index " << a << endl;
    }else {
          cout << "Match Not Found , return val " << a << endl;
    }

}
