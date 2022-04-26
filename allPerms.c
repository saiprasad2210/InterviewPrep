#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void swap(int &a, int &b) {
    int t = a;

    a = b;
    b = t;
}

void findPerms(vector<int> &a, int l) {
    
    if (l == a.size()) {
        //cout << a << endl;

        for (auto i : a) {
            cout << i << " ";
        }

        cout << endl;

        return;
    }

    for (int j = l; j < a.size(); j++) {
         swap(a[l],a[j]);
         findPerms(a,l+1);
         swap(a[j],a[l]);
    }
}
/*
void findPerms(vector<int> a, int lo, int hi) {
      if (lo > hi) {
          return;
      } 

      if (lo == hi) {
          cout << a[lo] << " ";
          return;
      }

      for (int i = 0; i < a.size(); i++) {
           cout << a[i] << " ";
           findPerms(a, 0,  i-1);
           findPerms(a, i+1, a.size());
           cout << endl;
      }
}





int main() {
    vector<int> a = {1,2,3,4};
    

    findPerms(a,0);
}