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


int find(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 
  

Node* buildUtil(int in[], int post[], int inStrt, 
                int inEnd, int& pidx) 
{
    int val, inIdx ;

    if (inStrt > inEnd) {
        return NULL;
    }

    val = post[pidx--];
    Node *root = new Node(val);

    inIdx = find(in, inStrt, inEnd,val); 
    root->right = buildUtil(in,post,inIdx+1, inEnd,pidx);
    root->left  = buildUtil(in,post,inStrt,inIdx-1,pidx);

    return root;
}

Node* buildTree(int in[], int post[], int n) 
{ 
    int pIndex = n - 1; 
    return buildUtil(in, post, 0, n - 1, pIndex); 
}

/* This funtcion is here just to test  */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->val); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int main() 
{ 
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n = sizeof(in) / sizeof(in[0]); 
  
    Node* root = buildTree(in, post, n); 
  
    cout << "Preorder of the constructed tree : \n"; 
    preOrder(root); 
  
    return 0; 
}   
