#include <iostream>
#include <map>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void calcHdist(Node * root, int  init, int  depth , map<int, pair<int, int> > &hmap) {
    
    if (!root) 
        return;
    
    // Build hmap
    if (hmap.find(init) == hmap.end()) {
        hmap[init] =  pair<int,int>(root->data, depth);
    } else {
        if (depth < hmap[init].second) {
            hmap[init] = pair<int,int>(root->data, depth);
        }
    }
    
    calcHdist(root->left, init  - 1,depth+1,  hmap);
    
    calcHdist(root->right, init + 1, depth+1, hmap);
    
}

void topView(Node * root) {

    map<int, pair<int,int> > hmap;
    
    calcHdist(root, 0, 0, hmap);
    
   
    
    
    for(auto i : hmap) {
        cout << i.second.first << " ";
    }
    
    cout << endl;
}

int main() {
}
