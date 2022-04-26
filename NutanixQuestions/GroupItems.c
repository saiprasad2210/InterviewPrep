#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

// Sorts  string elements based on count first and then alphabetically
void GroupItems(vector<string> &items) {

    unordered_map<string, int> smap;

    map<int, vector<string>, greater<int> > out;

    int n = items.size();

    // Find frequencies of each item
    for (auto str : items) {
        if (smap.find(str) == smap.end()) {
            smap[str] = 1;
        } else {
            smap[str]++;
        }
    }

    // Store Key:Count --> Val:Items Vector in ordered map
    for (auto it = smap.begin(); it != smap.end(); it++) {
         int count = it->second;
         string str = it->first;

         if (out.find(count) == out.end()) {
             vector<string> v;
             v.push_back(str);
             out[count] = v;
         } else {
             out[count].push_back(str);
         }
    }


    for (auto it = out.begin(); it != out.end(); it++) {
         // Sort elements
         sort(it->second.begin(), it->second.end());
         cout << "Elements with count " << it->first << endl;
         for (auto str: it->second) {
              cout << str << endl;
         }
    }
}

//O(n) version
void GroupItems2(vector<string> &items) {

    unordered_map<string, int> smap;
    /*
     * This is a BST which stores in Decreasing order of Counts.
     * and maintains string as another BST in asecnding order.
     * This is to avoid sorting.
     */
    map<int, map<string,int >, greater<int> > out;

    int n = items.size();

    // Find frequencies of each item
    for (auto str : items) {
        if (smap.find(str) == smap.end()) {
            smap[str] = 1;
        } else {
            smap[str]++;
        }
    }

    // Store Key:Count --> Val:Items Vector in ordered map
    for (auto it = smap.begin(); it != smap.end(); it++) {
         int count = it->second;
         string str = it->first;

         if (out.find(count) == out.end()) {
             map<string, int> v;
             v[str]=1;
             out[count] = v;
         } else {
             out[count][str] = 1;
         }
    }


    for (auto it = out.begin(); it != out.end(); it++) {
         cout << "Elements with count " << it->first << endl;
         for (auto str: it->second) {
              cout << str.first << endl;
         }
    }
}

int main() {
  vector<string> items;


  items.push_back("notebook");
  items.push_back("mouse");
  items.push_back("notebook");
  items.push_back("mouse");
  items.push_back("zen");
  items.push_back("zen");
  items.push_back("zen");
  items.push_back("opt");
  items.push_back("opt");
  items.push_back("opt");

  // Sorts above lements based on count first and then alphabetically
  GroupItems2(items);
}
