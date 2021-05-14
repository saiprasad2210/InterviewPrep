#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;



typedef struct TreeNode {
     int key;
     int val;
     int count;
     TreeNode *left;
     TreeNode *right;

public:
     TreeNode(int x,int y) {
       key = x;
       val =y;
       left = NULL;
       right= NULL;
       count = 0;
     }
} Node;


class BST {
      Node *root;

  public:

      BST() {
         root = NULL;
      }

      ~ BST() {
        cleanup(this->root);
      }


      Node* insert (Node *r, int key, int val);
      void insert(int key, int val);

      int get(Node *r, int key);
      int get(int key);

      void cleanup(Node *r);

      void inorder(Node *r);
      void inorder(void);

      Node* min(void);
      Node* min(Node *root);

      Node* max(void);
      Node* max(Node *root);

      int rank(int key);
      // runs in o(n)
      void rank(Node* root, int key, int &c, bool &is_found);
      // Runs in O(log n)
      int rank(Node *r, int key);


      int select (int rank);
      // runs in o(n)
      void select(Node *root, int &rank, int &key);
      // runs in o(log n)
      Node *select (Node *root,int k);


      int count();
      int count(Node *root);

      int floor(int key);
      void floor(Node *r, int key, int &flr);


      Node* deleteMin(Node * root);
      Node* deleteMin(void);

      void deleteKey(int key);
      Node* deleteKey(Node *root, int key);

      void keys(Node *root, int lo, int hi);
      void keys(int lo, int hi);

      int height(Node *root);
      int height();
};

int size(Node *r);

int BST::height(Node *root) {
    if (!root) {
        return 0;
    }

    int lh = 1 + height(root->left);
    int rh = 1 + height(root->right);
    return(std::max(lh,rh));
}

int BST::height() {
    return(height(root));
}


void BST::keys(int lo, int hi) {
     keys(root,lo,hi);
}

void BST::keys(Node *r, int lo, int hi) {
      if (r == NULL) {
          return;
      }

      if (lo < r->key) {
          keys(r->left,lo,hi);
      }

      if (r->key >= lo && r->key <= hi) {
          cout << r->key << endl;
      }

      if (hi > r->key) {
          keys(r->right,lo,hi);
      }
}


void BST::deleteKey(int key) {
      this->root = deleteKey(root,key);
}

Node* BST::deleteKey(Node *r, int key) {
     Node *x;

     if (!r) {
         return NULL;
     }

     if (key < r->key) {
         r->left = deleteKey(r->left,key);
     } else if (key > r->key) {
         r->right = deleteKey(r->right,key);
     } else {
         if (!r->right) {
             Node *tmp = r->left;
             delete r;
             return tmp;
         } else if (!r->left) {
             Node *tmp = r->right;
             delete r;
             return tmp;
         } else {
            // Replace Node with its inorder successor.
            Node *x = min(r->right);
            r->key = x->key;
            r->val = x->val;
            r->right = deleteMin(r->right);
            r->count = 1 + size(x->left) + size(x->right);
            return r;
         }
     }

     r->count = 1 + size(r->left) + size(r->right);
     return r;
}

Node* BST::deleteMin() {
    return deleteMin(root);
}

Node* BST::deleteMin(Node * root) {
      Node *tmp = NULL;

      if (root->left == NULL) {
          tmp = root->right;
          delete root;
          return tmp;
      }
      root->left = deleteMin(root->left);
      // recalculate sizes after deletion
      root->count = 1 + size(root->left) + size(root->right);
      return root;
}

void BST::floor(Node *r, int key, int &flr) {


      if (r == NULL) {
          return;
      }

      if (key == r->key) {
          flr = key;
          return;
      } else if (key < r->key) {
          floor(r->left,key, flr);
      } else {

          if (r->key > flr) {
              flr = r->key;
          }

          floor(r->right, key, flr);
      }
}

int BST::floor(int key) {
     int flr = INT_MIN;

     floor(root, key, flr);

     if (flr == INT_MIN)
         return -1;

     return flr;
}

int BST::count(Node *root) {

     if (root == NULL) {
       return 0;
     }

     int lt = count(root->left);
     int rt = count(root->right);

     return (1+lt+rt); //root + right tree + left tree
}

int BST::count(void) {
     return root->count;
}

int size(Node *r) {

  if (r == NULL)
      return 0;
  else
      return r->count;
}

// Runs in O(log n)
Node* BST::select(Node *root, int k) {
    int t;

    if (root == NULL ) {
        return NULL;
    }

    t = size(root->left) +1;

    if (t > k) {
        return select(root->left, k);
    } else if (t < k) {
        return select(root->right, k-t);
    } else {
        return root;
    }
}

// Runs in O(n) time
void BST::select(Node *r, int &rank, int &key) {
     if (r == NULL || rank == 0) {
         return;
     }

     select(r->left,rank,key);
     cout << "key is " << r->key << endl;

     if (rank != 0) {
         rank--;
         if (rank == 0) {
             key = r->key;
         }
     }
     select(r->right,rank,key);
}


int BST::select(int rank) {
    int key = -1;

    if (rank < 1)  {
        return -1;
    }

    if (rank > root->count) {
        return -1;
    }

    //select(root,rank,key);
    key = select(root, rank)->key;
    return key;
}

// Runs in O(log n) time

int BST::rank(Node *r, int key) {
    if (r == NULL) {
        return 0;
    }

    if (key < r->key) {
        return rank(r->left,key);
    } else if (key > r->key) {
        return 1 + size(r->left) + rank(r->right,key);
    } else {
        return size(r->left);
    }
}

// Runs in O(n) time
void BST::rank(Node *r, int key, int &c, bool &is_found) {

    if (r == NULL || is_found == true) {
       return;
    }

    cout << "calling key " << r->key << endl;


    rank(r->left,key,c,is_found);
    cout << "key is " << r->key << endl;
    if (!is_found) {
        if (r->key == key) {
            cout << "Returning " << c << " for key " << key << endl;
            is_found = true;
            return;
        } else {
            c++;
        }
   }
   rank(r->right,key,c,is_found);
}

int BST::rank(int key) {
    int c = 0;
    bool is_found = false;

    /* o(n) func logic
    rank(this->root, key, c, is_found);
    if (is_found) {
        return c+1;
    } else {
        return -1;
    }*/

    return rank(this->root, key);


}

Node* BST::min() {
      Node *min,*prev = NULL;

      min = this->root;

      while (min != NULL) {
             prev = min;
             min = min->left;
      }

      return prev;

}

Node* BST::min(Node *root) {

     if (!root->left) {
          return root;
     }

     return min(root->left);
}

Node* BST::max() {
     return max(this->root);
}

Node* BST::max(Node *root) {
     if (root->right == NULL) {
         return root;
     }
     return max(root->right);
}

void BST::cleanup(Node *r) {
     if (!r) {
        return;
      }
     cleanup(r->left);
     cleanup(r->right);
     //cout << "Cleanup " << r->key << endl;
     delete r;
}

Node* BST::insert (Node *r, int key, int val) {
     if (!r) {
         r = new Node(key,val);
         r->count = 1;
     } else {
        if (key > r->key) {
            r->right = insert(r->right,key,val);
            r->count++;
        } else if (key < r->key){
            r->left = insert(r->left,key,val);
            r->count++;
        } else {
            // if key exists update
            r->val = val;
        }
     }
     return r;
}

void BST::insert(int key, int val) {
     this->root = insert(this->root,key,val);
}

int BST::get(Node *r, int key) {
    if (r == NULL) {
        return -1;
    }

    //cout << r->key << endl;

    if (r->key == key) {
        return r->val;
    }

    if (key > r->key) {
        return(get(r->right,key));
    } else {
        return(get(r->left,key));
    }
}

int BST:: get(int key) {
    return(get(this->root,key));
}
void BST::inorder(Node *r) {
    if (r == NULL) {
       return;
    }

    inorder(r->left);
    cout << r->key << endl;
    inorder(r->right);
}

void BST::inorder(void) {
    inorder(root);
}



int main(int argc, char *argv[]) {
    BST bst = BST();
    bst.insert(5,55);
    bst.insert(2,22);
    bst.insert(1,11);
    bst.insert(3,33);
    bst.insert(4,44);
    bst.insert(8,88);
    bst.insert(6,66);
    bst.insert(9,99);

    bst.inorder();

    BST *b = new BST();
    b->insert(50,100);
    b->insert(80,800);
    b->insert(30,300);
    b->insert(90,900);

    cout << bst.get(9) << " " << bst.get(4) << endl;

    b->inorder();

    cout << bst.min()->key << " " << bst.max()->val << endl;

    //int key = atoi(argv[1]);

    //cout << b->floor(key) << endl;

    //int rank = atoi(argv[1]);
    //cout << bst.select(rank) << endl;

    //cout << "Size: " << bst.count() << endl;
    //cout << "Size: " << b->count() << endl;

    //int rank = atoi(argv[1]);
    //cout << "Select: " << rank << " = " << bst.select(rank) << endl;
    //bst.deleteKey(atoi(argv[1]));
    //bst.deleteMin();
    //bst.inorder();

    //b->deleteMin();
    //b->inorder();
    //bst.keys(4,10);
    cout << "Height: " << bst.height() << endl;
    cout << "Height: " << b->height() << endl;
    delete b;
}
