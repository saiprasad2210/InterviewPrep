#include "PQueue.h"

int main(int argc , char *argv[]) {
      int M = atoi(argv[1]);

      cout << M << endl;
      int i;

      PQueue<int> pq(M, minHeapify<int>);

      while (scanf("%d", &i)) {
            
            pq.insert(i);

            if (pq.size() > M) {
                cout << "del " << pq.delRoot() << endl;
            }

            pq.show();
      }

}

