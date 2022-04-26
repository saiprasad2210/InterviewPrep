#include <iostream>

using namespace std;

#define DOUBLE_LINK_LIST 2
#define SINGLE_LINK_LIST 1

class Node {
public:
  int val;
  Node *next;
  Node *prev;

  Node(int v) {
     val = v;
     next = NULL;
     prev = NULL;
  }
};


class linkList {
public:
    Node *head;
    Node *tail;
    int type;

    linkList(int type);
    Node* addNode(int key);
    void show();
    ~linkList();

};


linkList::linkList(int type) {
   this->type = type;
   head = NULL;
   tail = NULL;
}

linkList::~linkList() {

   Node *tmp;
   cout << "Cleanup" << endl;
   while (head) {
        tmp = head->next;
        delete head;
        head = tmp;
   }

}

Node* linkList::addNode(int key) {
    Node *n;
    n = new Node(key);
    if (head) {
        n->next = head;
        if (type ==  DOUBLE_LINK_LIST) {
            n->prev = NULL;
            head->prev = n;
        }

        head = n;
    } else {
        head = n;
        tail = head;
    }

    return head;
}

void linkList::show() {
   Node *t = head;
   while (t != NULL) {
      cout << t->val;
      t = t->next;
      if (t)
         cout << "<--->";
   }

   cout << endl;
}

linkList& mergeAlternate(linkList &l1, linkList &l2) {
     // Join the tail of first linkList with head of second
     /*
     l1.tail->next = l2.head;
     l2.head->prev = l1.tail;
     l2.head = NULL;
     */
     Node * h1 = l1.head;
     Node * h2 = l2.head;
     Node * t1;
     Node * t2;

     while (h1 && h2) {
        // Store pointers to next elements of each list
        t1 = h1->next;
        t2 = h2->next;

        // point next of first list to second
        h1->next = h2;
        h2->prev = h1;


        if (t1) {
           h2->next = t1;
           t1->prev = h2;
        }

        h1 = t1;
        h2 = t2;
     }

     // Set this to NULL so that cleanup happens l2 link list object
     l2.head = NULL;
     return l1;
}

int main() {
   linkList L1(DOUBLE_LINK_LIST), L2(DOUBLE_LINK_LIST);
   L1.addNode(10);
   L1.addNode(9);
   L1.addNode(4);
   L1.addNode(3);
   L1.addNode(2);
   L1.addNode(1);
   L1.show();
   //cout << "tail: " << L1.tail->val << endl;

   L2.addNode(8);
   L2.addNode(7);
   L2.addNode(6);
   L2.addNode(5);
   L2.show();
   //cout << "tail: " << L2.tail->val << endl;

   linkList &l = mergeAlternate(L1, L2);
   l.show();

}
