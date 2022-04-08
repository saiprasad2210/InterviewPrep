#include "PQueue.h"

template <class T>
class Item {
    public:

    T key;
    int vec_idx;
    int id;

    
        Item (T key, int idx, int id) {
            this->key = key;
            this->vec_idx = idx;
            this->id = id;
        }
};



static bool minHeapifyItems(Item<char> &a , Item<char> &b) {
    return a.key > b.key;
}


template <typename T>
void mSortedMerge(vector<vector<T>> &a, vector<T> &out) {
     int M = a.size();

     PQueue<Item<T>> pq(M, minHeapifyItems);

     for (int i = 0 ; i < M; i++) {
         Item<T> itm(a[i][0], i, 0);
         pq.insert(itm);
     }
    
     while(!pq.isEmpty()) {

         Item<T> itm = pq.delRoot();

         cout << itm.key << " ";

         out.push_back(itm.key);

         int idx = itm.vec_idx;
         int i  = itm.id;
         
         if (i < a[idx].size()) {
             Item<char> itNew(a[idx][i+1], idx, i+1);
              pq.insert(itNew); // insert next itm
         }


     }

     cout << endl;
}



int main(int argc , char *argv[]) {
    vector<vector<char>> a = {{'A', 'B', 'C', 'F', 'G', 'I', 'I', 'Z'},
                              {'B', 'D', 'H', 'P', 'Q', 'Q'},
                              {'A', 'B', 'E', 'F', 'J', 'N'}
                             };

    vector<char> out;

    mSortedMerge<char>(a,out);


}