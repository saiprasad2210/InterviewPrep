#include "unionFind.h"


class Edge {
    public:
       int src;
       int dst;
       int weight;

       Edge(int s, int d, int w) {
           src = s;
           dst = d;
           weight = w;
       }
};

static bool edgComp (Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

vector<Edge> kruskals_mst(vector<Edge> edgeList, int V) {

      // Sort Edges Based on Weight or we can also use a priority queue
      sort(edgeList.begin(), edgeList.end(), edgComp);

      // Create UnionFind Data Struture with V items
      
      WeightedQuickUnionUF Set(V);
      vector<Edge> mst;

      for (auto e : edgeList) {
           int s = e.src;
           int d = e.dst;
           int w = e.weight;

           // if two vertices are already connected adding new edge will lead to cycle.
           if (!Set.connected(s,d)) {
               Set.Union(s,d);
               mst.push_back(e);
           }
      }
 
      return mst;

}

int main() {
    vector<Edge> edgeList = {
        {0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
    };

    int V = 4 ;

    cout << "Minimum Cost Spanning Tree Edges: " << endl;
    for (auto e :  kruskals_mst(edgeList, V)) {
         cout << e.src << "--" << e.dst << " w: " << e.weight << endl; 
    }

}