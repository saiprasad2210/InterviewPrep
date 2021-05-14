/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#define TRUE  1
#define FALSE 0

class Solution {
    
public:
    
    Node* connect(Node* root) {
        
        if (!root) {
            return NULL;
        }
        
        root->next = NULL;
        connect(root,NULL,TRUE);
        return root;
    }
    
    void connect(Node* node, Node *parent, bool is_left) {
        if (!node) {
            return;
        }
        
        if (parent) {
            // Check if its right subtree or left
            if (is_left) {
            
                node->next = parent->right; 
        
            } else {
                if (parent->next) {
                    node->next = parent->next->left;
                } else {
                    node->next = NULL;  
                }
            }
        }
        
        connect(node->left,  node, TRUE);
        
        connect(node->right, node, FALSE);
        
    }
};
