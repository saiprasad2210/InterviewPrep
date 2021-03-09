#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubArr(vector<int> v) {

    int sum = 0, i =0, maxlen = 0;
    unordered_map<int,int> smap;

    for (auto it : v) {
         smap[sum+it] = i++;
         sum += it;
    }

    sum = 0; i = 0;
    for (auto it: v) {
         if (smap.find(sum) !=  smap.end()) {
            maxlen = max(maxlen, smap[sum] - i + 1);
         }
          sum += it;
          i++;
    }

    return maxlen;
}


int main () {
  int arr[] = {15,-2,2,-8,1,7,2,-17};
  vector<int> v(arr, arr+ sizeof(arr)/sizeof(arr[0]));

  cout << maxSubArr(v) << endl;
}
