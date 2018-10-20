/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max (int dr, int dl) {
    if (dr > dl) {
        return dr;
    }
    
    return dl;
}
int maxDepth(struct TreeNode* root) {
    int dr, dl;
    
    if (root == NULL) {
        return 0;
    }
    
    dr = 1 + maxDepth (root->right);
    dl = 1 + maxDepth (root->left);
    return (max(dr,dl));
    
}
