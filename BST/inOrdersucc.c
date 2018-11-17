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

Node * leftmostNode(Node *root) {

  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

Node* inOrderSuc(Node *root, int key) {
     Node *psuc = NULL;

     while (root) {
        if (root->val > key ) {
            psuc = root;
            root = root->left;
        } else if (root->val < key) {
            root = root->right;
         //inOrderSuc(root->left, key);
        } else {
             if (root->right) {
                return (leftmostNode(root->right));
             } else {
                return (psuc);
             }
        }
     }

     return NULL;

}

/* Give a binary search tree and a number, inserts a new node with
    the given number in the correct place in the tree. Returns the new
    root pointer which the caller should then use (the standard trick to
    avoid using reference parameters). */
Node* insert(Node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(new Node(data));
  else
  {
    Node *temp;

    /* 2. Otherwise, recur down the tree */
    if (data <= node->val)
    {
         temp = insert(node->left, data);
         node->left  = temp;
         //temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        //temp->parent = node;
    }

    /* return the (unchanged) node pointer */
    return node;
  }
}

int main () {
  Node *root = NULL,*psuc;
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  //temp = root->left->right->right;

  psuc = inOrderSuc(root,4);
  if (psuc)
      cout << "IN succ = " << psuc->val << endl;
  else
      cout << "NULL" << endl;
}
