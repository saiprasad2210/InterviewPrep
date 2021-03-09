#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool compArr(vector<int> & v1, vector<int> &v2) {

  unordered_map<int,int> nmap;

  if (v1.size() != v2.size()) {
      return false;
  }

  for (auto i = v1.begin(); i != v1.end(); i++) {
      if (nmap.find(*i) == nmap.end()) {
          nmap[*i] = 1;
      } else {
          nmap[*i]++;
      }
  }

  for (auto i = v2.begin(); i != v2.end();i++) {
    if (nmap.find(*i) == nmap.end()) {
        return false;
    } else {
        nmap[*i]--;
    }
  }

  for (auto &i : nmap) {
    if (i.second != 0) {
        return false;
    }
  }

  return true;
}

int main () {
  int arr1[]  = {2,5,6,8,10,2,2};
  int arr2[]  = {2,5,6,8,10,2,2};
 
  vector<int> v1(arr1, arr1+ sizeof(arr1) /sizeof(arr1[0]));
  vector<int> v2(arr2, arr2+ sizeof(arr2) /sizeof(arr2[0]));

  for (auto &i : v1) {
     cout << i << " " ;
  }
  
  cout << endl;

  cout << compArr(v1,v2) << endl;
}
