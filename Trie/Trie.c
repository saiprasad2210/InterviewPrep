#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define ALPHABHHET_RANGE 256


class Trie {

    Trie *child[ALPHABHHET_RANGE];
    int val;

public:
    /** Initialize your data structure here. */
    Trie() {
        // Set to NULL
        for (int i = 0; i < ALPHABHHET_RANGE; i++) {
            child[i] = NULL;
        }
        // Set to invalid
        val = -1;
    }

    ~ Trie() {
        cout << "Deleting " <<  endl;

    }


    /** Inserts a word into the trie. */
    Trie* insert(Trie *t , string &key, int val, int i) {

          if (t == NULL) {
              t = new Trie();
          }

          if (i == key.size()) {
              t->val = val;

              return t;
          }

          t->child[key[i]] = insert(t->child[key[i]],key,val,i+1);

          return t;
    }

    void insert(string key) {
         Trie *root = this;
         int i = 0, val = 1;
         insert(root,key,val,i);
    }

    bool search(Trie *t, string &key, int i) {

      if (t == NULL) {
          return false;
      }

      if (i == key.size()) {
         if (t->val > 0) {
             return true;
         }else {
             return false;
         }
      }

      return(search(t->child[key[i]],key,i+1));
    }

    /** Returns if the word is in the trie. */
    bool search(string key) {
       Trie *root = this;
       return search(root, key, 0);
    }

    bool startsWith(Trie *t, string &key, int i) {
      if (t == NULL) {
          return false;
      }

      if (i == key.size()) {
          return true;
      }

      return (startsWith(t->child[key[i]],key,i+1));

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Trie *root = this;
         return startsWith(root,prefix,0);

    }

    void collect(Trie *t, string pre, vector<string> &q) {
           if (t == NULL) {
               return;
           }

           if (t->val > 0) {
               q.push_back(pre);
           }

           for (int i = 0 ; i < ALPHABHHET_RANGE; i++) {
                collect(t->child[i], pre + (char)i, q);
           }
    }

    Trie* getNodeAtPrefix(Trie *t, string &pre, int i) {

      if (t == NULL) {
          return t;
      }

      if (i == pre.size()) {
          return t;
      }

      return(getNodeAtPrefix(t->child[pre[i]],pre,i+1));
    }

    void keysWithPrefix(Trie *t, string &pre, vector<string> &q) {

         Trie* node = getNodeAtPrefix(t,pre,0);
         collect(node, pre, q);
    }

    void keysWithPrefix(string &pre, vector<string> &q) {
         Trie * root = this;
         keysWithPrefix(root,pre,q);
    }


    int longestPrefixMatch(Trie *t, string &pre, int len, int i) {

         if (t == NULL) {
             return len;
         }

         if (t->val > 0) {
              len = i;
         }

         if (pre.size() == i) {
             return len;
         }
         //printf("\n%d\n", pre[i]);
         return longestPrefixMatch(t->child[pre[i]], pre, len, i+1);
    }

    Trie* delKey(Trie *t, string key, int d) {

          if (t == NULL) {
              return t;
          }

          if (d == key.length()) {
              t->val = -1;
          } else {
             t->child[key[d]] = delKey(t->child[key[d]], key, d+1);
          }

          if (t->val > 0) {
              return t;
          }

          for (int i = 0; i < ALPHABHHET_RANGE; i++) {
               if (t->child[i] != NULL) {
                  return t;
               }
          }

          return NULL;
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 int main(int argc , char* argv[]) {

   string str[argc-1];
   vector<string> keys;

   for (int i = 0; i < argc-1; i++) {
        str[i] = argv[i+1];
   }

   Trie* obj = new Trie();

   for (int i =0; i < argc-1 ; i++) {
        obj->insert(str[i]);
   }

   // Iterate all the keys in the trie
   obj->collect(obj,"",keys);

   for (int i = 0; i < keys.size(); i++) {
       cout << keys[i] << endl;
   }

   keys.clear();

   string pre = "sa";

   cout << "Keys with Prefix " << pre << endl;

   obj->keysWithPrefix(pre, keys);

   for (int i = 0; i < keys.size(); i++) {
       cout << keys[i] << endl;
   }

   string pre1 = "saiprasad";
   int lpm = obj->longestPrefixMatch(obj,pre1, 0, 0);
   cout << "LPM of saiprasad " << pre1.substr(0,lpm) << endl;

   cout << "Deleting key saipt" << endl;
   string key = "saipt";
   obj->delKey(obj, key, 0);

   keys.clear();
   obj->collect(obj,"",keys);

   for (int i = 0; i < keys.size(); i++) {
       cout << keys[i] << endl;
   }
 }
