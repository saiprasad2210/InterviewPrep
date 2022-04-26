#ifndef _EDGE_WEIGHTED_GRAPH_

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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


class EdgeWeightedGraph {
     int V;
     int E;
     bool is_directed;
     vector<vector<Edge>> adj;

public:

     EdgeWeightedGraph(int v, bool is_dir) {
         V = v;
         E = 0;
         is_directed = is_dir;
         adj.reserve(V);
     }

     void addEdge(Edge e) {
         adj[e.src].push_back(e);
         if (!is_directed) {
             Edge t(e.dst,e.src,e.weight);
             adj[e.dst].push_back(t);
         }
         E++;
     }

     vector<Edge> adjList(int v) {
         return adj[v];
     }

     int Vertex() { 
        return V; 
     }

     int Edges() { 
        return E; 
     }

};


#endif

/*
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

    DFS(G, 0);
}
*/