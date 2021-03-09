#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}Node;

bool bsearch (Node *root, int key) {

  while (root) {
    if (root->val == key) {
        return true;
    } else if (root->val < key) {
        root = root->right;
    } else {
        root = root->left;
    }
  }
   return false;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
 
    
	if (root == NULL) return NULL; 
        int n1 = p->val, n2 = q->val;

	// If both n1 and n2 are smaller than root, then LCA lies in left 
	if (root->val > n1 && root->val > n2) 
		return lowestCommonAncestor(root->left, p, q); 

	// If both n1 and n2 are greater than root, then LCA lies in right 
	if (root->val < n1 && root->val < n2) 
		return lowestCommonAncestor(root->right, p, q); 

	return root; 
} 

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
      Node *t1 = root, *t2 = root, *prev = NULL;

      // Check if q is decendent of p
      if (bsearch(p,q->val)) {
          return p;
      }

      // Check if p is decendent of q
      if (bsearch(q,p->val)) {
          return q;
      }

      while (t1 == t2) {
        if (p->val > t1->val) {
           t1 = t1->right;
        } else {
           t1 = t1->left;
        }

        if (q->val > t2->val) {
           t2 = t2->right;
        } else {
           t2 = t2->left;
        }

        prev = t1;

      }

      return prev;
}
