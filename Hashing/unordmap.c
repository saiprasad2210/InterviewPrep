#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
int main() 
{ 
    // Declaring umap to be of <string, int> type 
    // key will be of string type and mapped value will 
    // be of double type 
    unordered_map<string, int> umap; 
    
    // inserting values by using [] operator 
    umap["GeeksforGeeks"] = 10; 
    umap["Practice"] = 20; 
    umap["Contribute"] = 30; 
    //umap.insert({"sai", 40});
    umap["sai"]  = 40;
    umap["sai"]++;
    //cout << umap.find("sai") << endl;
    if (umap.find("sai") == umap.end()) {
        cout << "not found" << endl;
    } else {
        cout << umap.at("sai") << endl;
    }
    // Traversing an unordered map 
    for (auto &x : umap) { 
      cout << x.first << " " << x.second << endl;
      x.second++;
    }

    for (auto x : umap) {
      cout << x.first << " " << x.second << endl;
      x.second++;
    } 
  
} 
