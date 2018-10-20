/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isBST(struct TreeNode* root,int *prev,int *is_set) {
    
    int curr;
    
    if (!root) {
        return true;
    }
    
    
    if (!isBST(root->left,prev,is_set)) {
        return false;
    }
    
    curr = root->val;
    //printf ("1: %d -- %d \n", curr,*prev);
    if (curr <= *prev && *is_set) {
        return false;
    } else {
        *is_set = 1;
        *prev = curr;
    }
    
    if (!isBST(root->right,prev,is_set)) {
        return false;
    }
    
    return true;
}


bool isValidBST(struct TreeNode* root) {
    int prev = 0,is_set = 0;
    
    return(isBST(root,&prev,&is_set));
}
