#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"

using namespace std;


Graph::Graph(int v, bool is_directed) {
   V = v;
   E = 0;
   adj = new vector<int>[V];
   this->is_directed = is_directed;
}

void Graph::addEdge(int v, int w) {
   adj[v].push_back(w);
   // Add reverse edge only if graph is undirected.
   if (!is_directed) {
       adj[w].push_back(v);
   }
   E++;
}


vector<int> Graph::adjList(int v) {
  return adj[v];
}

vector<int>* Graph::adjListRef(int v) {
  return &adj[v];
}

int Graph::Vertex() {
  return V;
}

int Graph::Edges() {
  return E;
}
