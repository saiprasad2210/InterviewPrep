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


void BToDLL(Node* root, Node** head_ref) {
     static Node* prev = NULL;
     if (!root) {
       return;
     }

     BToDLL(root->left,head_ref);

     root->left  = prev;
     if (prev) {
        prev->right = root;
     } else {
       // first node
       *head_ref = root;
     }
     prev = root;

     BToDLL(root->right,head_ref);
}

void printDLL (Node *head) {
  while (head) {
    cout << head->val << " " ;
    head = head->right;
  }
}

int main () {
  /* Constructing below tree
               5
             /   \
            3     6
           / \     \
          1   4     8
         / \       / \
        0   2     7   9  */
    Node* root = new Node(5); 
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(8);
    root->left->left->left = new Node(0);
    root->left->left->right = new Node(2);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    Node* head = NULL;
    BToDLL(root, &head);

    printDLL(head);

    return 0;
}
