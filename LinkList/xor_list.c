#include <iostream>

using namespace std;

typedef struct Node 
{ 
    int data; 
    struct Node* npx; /* XOR of next and previous node */

    Node (int val) : data(val), npx(NULL) {}

} Xnode;

/* returns XORed value of the node addresses */
struct Node* XOR (struct Node *a, struct Node *b) 
{ 
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 

void insert(Xnode* &head_ref, int data) {
   Xnode *node = new Xnode(data);

   node->npx = XOR(NULL, head_ref);

   if (head_ref) {
     head_ref->npx = XOR(node,XOR(head_ref->npx,NULL)); 
   }

   head_ref = node;
}

void traverse(Xnode *head) {
   Xnode *next = NULL, *prev = NULL;

   if (!head) {
       return;
   }

   while (head) { 
      cout << head->data << " ";
      next = XOR(head->npx, prev);
      prev = head;
      head = next;
   }
   
   cout << endl;
}


int main () 
{ 
    /* Create following Doubly Linked List 
    head-->40<-->30<-->20<-->10 */
    Xnode *head = NULL; 
    insert(head, 10); 
    insert(head, 20); 
    insert(head, 30); 
    insert(head, 40); 
  
    // print the created list 
    traverse(head); 
  
    return (0); 
} 


