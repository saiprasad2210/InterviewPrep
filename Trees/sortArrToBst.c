#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} Node;


void levelorder (Node *root) {
     queue <Node *> q;
     Node *curr;

     q.push(root);

     while (!q.empty()) {
       curr = q.front();
       cout << curr->val << " ";

       if (curr->left) {
           q.push(curr->left);
       }

       if (curr->right) {
           q.push(curr->right);
       }

       q.pop();
     }

     cout << endl;
}
 
class Solution {
public:
    TreeNode* getMid(vector<int>& nums, int lo, int hi) {
       TreeNode* root = NULL;
       if (lo > hi) {
          return NULL;
       }  

       int mid = (lo + hi) / 2;
       root = new TreeNode(nums.at(mid));
       root->left   = getMid (nums, lo, mid-1);
       root->right  = getMid (nums,mid+1,hi);
       return root;
        

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       cout << "Size = " << nums.size() << endl; 
       return (getMid(nums,0,nums.size()-1));
        
    }
};

int main () {

    vector<int> g1; 
    Solution sl;  
    for (int i = 1; i <= 8; i++) 
        g1.push_back(i);

    levelorder(sl.sortedArrayToBST(g1));

}



