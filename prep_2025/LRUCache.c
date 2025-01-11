

class Node
{
    public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node (int key, int data) {
        this->key = key;
        this->value = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


class LRUCache {
    int C;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> hmap;

public:
    LRUCache(int capacity) {
        C = capacity;
 
        head = new Node(-1,-1); // special sentinel node
        tail = new Node(-1,-1); // special sentinel node
   
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
       if (hmap.find(key) == hmap.end()) {
           return -1;
       }

       Node *node = hmap[key];
       remove(node);
       add(node);
       return node->value;
    }
    
    void put(int key, int value) {
       
       // if node dont exist add it to list
       if (hmap.find(key) == hmap.end()) {
           Node *node = new Node(key,value);
           hmap[key] = node;

           if (hmap.size() > C) {
               Node *nodeToDel = tail->prev;
               remove(nodeToDel);
               hmap.erase(nodeToDel->key);
               delete nodeToDel;
            }

            add(node);
       } else {
           // if node exists just update val and move node to front
           Node *node = hmap[key];
           node->value = value;
           remove(node);
           add(node);
       }

    }

    void add(Node *node) {
        Node *tmp = head->next;

        head->next = node;
        node->prev = head;

        node->next = tmp;
        tmp->prev = node;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
