#include <iostream>
#include <unordered_map>
using namespace std;

char* remDup(char *str) {
     int last = 0;
     unordered_map<char,int> smap;
     for (int i = 0; str[i]; i++) {
         if (smap.find(str[i]) == smap.end()) {
            smap[str[i]] = 1;
            str[last] = str[i];
            last++; 
         }
     }
     str[last] = '\0';

     return str;
}


int main () {
    char str[] = "sasbhibahuid";
    cout << remDup(str) << endl;
}
