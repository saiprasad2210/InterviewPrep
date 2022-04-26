#include <iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &a, int k, int val) {
    int curr = 0;
    int m = 1;

    for (int i = 0; i < a.size(); i++) {
         if (a[i] > val) {
             return false;
         }

         if (curr+a[i] > val) {
             m++;
             curr = a[i];

             if (m > k) {
                 return false;
             }
         } else {
             curr += a[i];
         }
    }

    return true;

}

int paintPart(int A, int B, vector<int> &C) {

    int max_time = 0 , min_time = C[0];

    for (auto i: C) {
         if (i > min_time) {
             min_time = i;
         }
          
          max_time += i;
    }

    cout << min_time << "--" << max_time << endl;

    int lo = min_time;
    int hi = max_time;
    int opt;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        cout << mid << endl;
        if (isPossible(C,A,mid)) {
            hi = mid-1;
            opt = mid; 
        } else {
            lo = mid+1;
        }
    }

    return (opt * B);
}

int main () {
    vector<int> v = {640, 435, 647, 352, 8, 90, 960, 329, 859 };

    cout << paintPart(3,10,v) << endl;
}