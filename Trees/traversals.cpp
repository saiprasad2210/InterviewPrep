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
 
void  inorder_iter(Node *root) {
     stack <Node *> s;
     Node *curr = NULL;

     curr = root;

     while (curr || !s.empty()) {
        
         while (curr) {
            s.push(curr);
            curr = curr->left;
         }

         
         curr = s.top();
         s.pop();
         cout <<  curr->val << " ";

         curr = curr->right;   

     }
     
     cout << endl;    
}

void  preorder_iter(Node *root) {
     stack <Node *> s;
     Node *curr = NULL;

     curr = root;

     while (curr || !s.empty()) {

         /* Reach the left most Node of the 
           curr Node */
         while (curr) {
            cout <<  curr->val << " ";
            s.push(curr);
            curr = curr->left;
         }

         /* Current must be NULL at this point */

         curr = s.top();
         s.pop();
        
         /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */

         curr = curr->right;

     }

     cout << endl;
}

// Using two stacks
void  postorder_iter(Node *root) {
     stack <Node *> s;
     stack <Node *> r;

     Node *curr = NULL;

     curr = root;

     while (curr || !s.empty()) {

         /* Reach the left most Node of the
           curr Node */
         while (curr) {
            //cout <<  curr->val << " ";
            r.push(curr);
            s.push(curr);
            curr = curr->right;
         }

         /* Current must be NULL at this point */

         curr = s.top();
         s.pop();

         /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */

         curr = curr->left;

     }

     while (!r.empty()) {
         curr = r.top();
         r.pop();
         cout <<  curr->val << " ";
     }

     cout << endl;
}

// Post order using single stack

void postorder_iter2 (Node *root) {
     stack <Node *> s;

     Node *curr = NULL;
     Node *prev = NULL;

     curr = root;
     s.push(curr);

     while (curr && !s.empty()) {
         if (!curr->right && !curr->left) {
             cout <<  curr->val << " ";
             prev = s.top();
             s.pop();
         } else if (prev && (curr->right == prev || curr->left == prev)) {
             cout <<  curr->val << " ";
             prev = s.top();
             s.pop();
         } else {
             if (curr->right) {
                 s.push(curr->right);
             } 
             if (curr->left) {
                 s.push(curr->left);
             }
         } 

         if (!s.empty())
             curr = s.top();   
     }

     cout << endl;
}

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

int main () {
    Node *root = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3); 
    root->left->left   = new Node(4); 
    root->left->right  = new Node(5); 
    root->right->left  = new Node(6);
    root->right->right = new Node(7); 
    root->right->right->left = new Node(8);
    inorder_iter(root);
    preorder_iter(root);
    postorder_iter2(root);
    levelorder(root); 
}




