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


class Solution {
public:
   bool countStree(TreeNode* root, int &count) {

        if (!root) {
            return false;
        }

        if (!root->left && !root->right){
            return true;
        }
      
        if (countStree(root->left, count)) {
            count++;
        }
       
        if (countStree(root->right, count)) {
            count++;
        }

        if (root->left && root->right) {
           if (root->left->val == root->right->val &&
               root->val       == root->left->val) {
               //count++;
               return true;
           }
        } else if (root->left) {
           if (root->left->val == root->val) {
               //count++;
               return true;
           }

        } else {
           if (root->right->val == root->val) {
               //count++;
               return true;
           }
        }
        
        return false;
   }
};

int main () {
    int count = 0;
    Node *root = new Node(5);
    root->left         = new Node(4);
    root->right        = new Node(5);
    root->left->left   = new Node(4);
    root->left->right  = new Node(4);
    root->right->right = new Node(5);

    Solution sl;

    sl.countStree(root,count);
    cout << "Count is " << count << endl; 

}
