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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        
      
        if (!root->left && !root->right){
            if (sum == root->val) {
                return true;
            } else {
                return false;
            }
        }
        
        if (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val) ) {
            return true;
        } 
        
        return false;
        
        
    }
};

int main () {


}
