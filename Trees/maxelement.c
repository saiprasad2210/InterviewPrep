#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;

     TreeNode (int data) {
         val = data;
         left = right = NULL;
     }
};

typedef struct TreeNode Node;

void maxTree (Node *root, int &max) {
    
    if (!root) {
        return;
    }

    if (root->val > max) {
        max = root->val; 
    }

    maxTree(root->left, max);
    maxTree(root->right,max); 
}

int maxTree2 (Node *root) {
   int l , r, max = INT_MIN;
   if (root != NULL) {
      
       l = maxTree2 (root->left);
       r = maxTree2 (root->right);

       if (l > r) {
           max = l;
       } else {
           max = r;
       }
      
       if (root->val > max) {
          max = root->val;
       }
   }

   return max;

}

bool treesrch(Node *root, int key) {

     if (!root) {
         return false;
     }

     if (root->val == key) {
         return true;
     } 

     if (treesrch(root->left, key) || treesrch(root->right, key)) {
         return true;
     }
 
     return false;
     
}


int main () {
    int max;
    Node *root = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    //max = root->val;
    //maxTree(root, max);
    max = maxTree2(root);

    cout << max << endl;

    cout << treesrch(root, 10) << endl;
}



 
