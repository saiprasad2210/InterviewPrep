#include <iostream>
#include <vector>
#include <queue>
#include "EdgeWeightedGraph.h"

using namespace std;

typedef struct Vertex_ {
    int ver;
    int greedyCriteria;

    Vertex_(int v, int gc) {
        ver = v;
        greedyCriteria = gc;
    }
} Vertex;

//minHeap
bool operator<(const Vertex v1, const Vertex v2) {
    return v1.greedyCriteria > v2.greedyCriteria;
}

class DijkstraSP {

    int SrcVertex;
    int N;
    vector<int> distTo;
    vector<int> pathTo;
    priority_queue<Vertex> mPQ;
    

public:

     DijkstraSP(EdgeWeightedGraph &G, int src) {
         SrcVertex = src;
         int V = G.Vertex();
         N =V;
         distTo.reserve(V);
         pathTo.reserve(V);

         for (int i=0; i < V; i++) {
             distTo[i] = INT_MAX;
         }

         distTo[src] = 0;
         pathTo[src] = src; 
        
         mPQ.push((Vertex) {src,0});

         while(mPQ.size()) {
              Vertex v = mPQ.top();
              mPQ.pop();
              relax(G,v.ver);
         }

     }

     void relax(EdgeWeightedGraph &G, int src) {

         for (auto e: G.adjList(src)) {
              int w = e.dst;
              if (distTo[w] > distTo[src]+ e.weight) {
                  distTo[w] =  distTo[src]+ e.weight;
                  pathTo[w] = src;
                  mPQ.push((Vertex) {w,distTo[w]});
              }
         }
     }

     int distToVertex(int v) {
          return distTo[v];
     }

     void printPathTo(int v) {
         
         while (pathTo[v] != v) {
             cout << v << " -- ";
             v = pathTo[v];
         }

         cout << v;

         cout << endl;
     }

     void printAllDist () {
         cout << "Src: " << SrcVertex << endl;

         cout << "Sz: " << N << endl;

         for (int d = 0; d < N; d++) {
              cout << d << " dist: " << distTo[d] << endl;
         } 

         cout << endl;
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
    int src = 0;
    int dst = 4;
    DijkstraSP spt(G,src);

     
    cout << spt.distToVertex(dst) << endl;

    spt.printPathTo(dst);

    spt.printAllDist();

}