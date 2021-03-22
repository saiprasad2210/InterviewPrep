#include <iostream>
#include <string.h>

using namespace std;

#define MAX_ALPHABHHET 255

void countSort(char arr[]) {
    int count[MAX_ALPHABHHET+1];
    int len = strlen(arr);
    char aux[len];
    int R = MAX_ALPHABHHET;

    memset(count,0, sizeof(count));

    // Compute frequency counts
    for (int i = 0; i < len; i++) {
         int idx = arr[i];
         count[idx+1]++;
    }

    // Transform counts to indices. By taking Cumulative source_img

    for (int r =0 ; r < R; r++) {
         count[r+1] += count[r];
    }

    // Distribute the records as per index
    for (int i = 0; i < len; i++) {
         aux[count[arr[i]]++] = arr[i];
    }

    //copy back to original array
    for (int i = 0; i < len; i++) {
         arr[i] = aux[i];
    }

}

// Assumes equal sized words
void countSort(string str[], int N, int d) {
    int count[MAX_ALPHABHHET+1];
    string aux[N];
    int R = MAX_ALPHABHHET;

    memset(count,0, sizeof(count));

    // Compute frequency counts
    for (int i = 0; i < N; i++) {
         int idx = str[i].at(d);
         count[idx+1]++;
    }

    // Transform counts to indices. By taking Cumulative source_img

    for (int r =0 ; r < R; r++) {
         count[r+1] += count[r];
    }

     // Distribute the records as per index
    for (int i = 0; i < N; i++) {
         int idx = count[str[i].at(d)]++;
         aux[idx] = str[i];
         //aux[count[str[i].at(d)]++] = str[i];
    }

    //copy back to original array
    for (int i = 0; i < N; i++) {
         str[i] = aux[i];
    }

}

// Assumes variable sized words
void countSort2(string str[], int N, int d) {
    int count[MAX_ALPHABHHET+1];
    string aux[N];
    int R = MAX_ALPHABHHET;
    int idx;

    memset(count,0, sizeof(count));

    // Compute frequency counts
    for (int i = 0; i < N; i++) {
         if (d < str[i].size()) {
             idx = str[i].at(d);
         } else {
             idx = '\0';
         }
         count[idx+1]++;
    }

    // Transform counts to indices. By taking Cumulative source_img

    for (int r =0 ; r < R; r++) {
         count[r+1] += count[r];
    }

     // Distribute the records as per index
    for (int i = 0; i < N; i++) {
         if (d < str[i].size()) {
             idx = count[str[i].at(d)]++;
         } else {
             idx = count['\0']++;;
         }
         aux[idx] = str[i];
    }

    //copy back to original array
    for (int i = 0; i < N; i++) {
         str[i] = aux[i];
    }

}


void radixSortLSD(string str[], int N) {
     int W = 0;

     for (int i = 0; i < N; i++ ) {
          if (str[i].size() > W) {
              W = str[i].size();
          }
     }


     for (int d = W-1; d >= 0; d--) {
          countSort2(str, N, d);
     }
}


// Driver  code
int main(int argc , char *argv[])
{
    //char arr[] = "geeksforgeeks";
    string str[argc-1];

    for (int i = 0; i < argc-1; i++) {
         str[i] = argv[i+1];
    }

    //countSort(str, argc-1, 0);
    radixSortLSD(str, argc-1);

    for (int i =0; i < argc-1 ; i++)
         cout << str[i] << endl;

    return 0;
}
