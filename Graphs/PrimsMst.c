#include <iostream>
#include <vector>
#include <queue>
#include "EdgeWeightedGraph.h"

using namespace std;



void DFS(EdgeWeightedGraph &G, int v, bool visited[]) {
    
   cout << v << " " << endl;

   visited[v] = 1;
   for (auto e : G.adjList(v)) {
       if (!visited[e.dst]) {
           DFS(G,e.dst,visited);
       }
   }

}

void DFS(EdgeWeightedGraph &G, int s) {
    int n = G.Vertex();
    bool visited[n];

    for (int i = 0; i < n; i++) {
       visited[i] = 0;
    }

    DFS(G, s, visited);
}

bool operator<(const Edge e1, const Edge e2) {
    return e1.weight > e2.weight;
}

class LazyPrimMST {
     vector<bool> marked;
     vector<Edge> mst;
     priority_queue<Edge> mPQ;

public:

     LazyPrimMST(EdgeWeightedGraph &G) {
           marked.reserve(G.Vertex());
           
           for (int i = 0; i < G.Vertex(); i++) {
               marked[i] = false;
           }

           visit(G,0);


           while(mPQ.size()) {
               Edge minEdge = mPQ.top();
               mPQ.pop();

               int s = minEdge.src;
               int d = minEdge.dst;
               int w = minEdge.weight;

               //cout << s << ", " << d << ", " << w << endl;

               if (marked[s] && marked[d]) {
                   // both of them are already in tree with min edge added to mst
                   continue;
               }

               mst.push_back(minEdge);

               if (!marked[s]) {
                   visit(G, s); // Add vertex to tree
               }

               if (!marked[d]) {
                   visit(G, d);
               }
           }
    
     }

     void visit(EdgeWeightedGraph &G, int v) {
          marked[v] = true;

          for (auto e: G.adjList(v)) {
               if (!marked[e.dst]) {
                   
                   mPQ.push(e);
               }
          }
     }

     vector<Edge> edges() {
         return mst;
     }


};


int main() {
    int V = 9;
    EdgeWeightedGraph G(V,false);
        
    G.addEdge((Edge){0, 1, 4});
    G.addEdge((Edge){0, 7, 8});
    G.addEdge((Edge){1, 2, 8});
    G.addEdge((Edge){1, 7, 11});
    G.addEdge((Edge){2, 3, 7});
    G.addEdge((Edge){2, 8, 2});
    G.addEdge((Edge){2, 5, 4});
    G.addEdge((Edge){3, 4, 9});
    G.addEdge((Edge){3, 5, 14});
    G.addEdge((Edge){4, 5, 10});
    G.addEdge((Edge){5, 6, 2});
    G.addEdge((Edge){6, 7, 1});
    G.addEdge((Edge){6, 8, 6});
    G.addEdge((Edge){7, 8, 7});

    //DFS(G, 0);

    LazyPrimMST mst(G);

    for(auto e: mst.edges()) {
        cout << e.src << "---" << e.dst << ", Wgt " << e.weight << endl;
    }
}