#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"



GraphSearch::GraphSearch(Graph &G, int s, search_type_t stype) {

    if (stype == BFS_SEARCH) {
        BFS(G,s);
    } else if (stype == DFS_SEARCH) {
        DFS(G,s);
    }
}

void GraphSearch::BFS(Graph &G, int s) {
  queue<int> q;
  int node;
  int visited[G.Vertex()];
  int dist[G.Vertex()];

  for (int i = 0; i < G.Vertex(); i++) {
       visited[i] = 0;
       dist[i] = INT_MAX;
  }

  q.push(s);
  visited[s] = 1;
  dist[s] = 0;
  while (!q.empty()) {
     node = q.front();
     cout << node <<  " : " << dist[node] << endl;
     q.pop();

     for (auto i: G.adjList(node)) {
       if (visited[i] == 0) {
            q.push(i);
            visited[i] = 1;
            dist[i] = dist[node] +1;
       }
     }
  }
  cout << endl;
}

void GraphSearch::BFS(Graph &G, int s, int visited[], int dist[], int pred[]) {
  queue<int> q;
  int node;

  q.push(s);
  visited[s] = 1;
  dist[s] = 0;
  while (!q.empty()) {
     node = q.front();
     cout << node <<  " : " << dist[node]  << " --> pred: " << pred[node] << endl;
     q.pop();

     for (auto i: G.adjList(node)) {
       if (visited[i] == 0) {
            q.push(i);
            visited[i] = 1;
            dist[i] = dist[node] +1;
            pred[i] = node;
       }
     }
  }
  cout << endl;
}


void GraphSearch::DFS(Graph &G, int v, bool visited[]) {

   cout << v << " " << endl;
   visited[v] = 1;
   for (auto i : G.adjList(v)) {
       if (!visited[i]) {
           DFS(G,i,visited);
       }
   }

}

// this DFS varaint is used for topo topoSort.
void GraphSearch::DFS(Graph &G, int v, bool visited[], int topo[], int &curr_label) {

   //cout << v << " " << endl;
   visited[v] = 1;
   for (auto i : G.adjList(v)) {
       if (!visited[i]) {
           DFS(G,i,visited,topo,curr_label);
       }
   }

   topo[v] = curr_label;
   curr_label--;
}

void GraphSearch::DFS(Graph &G, int s) {
   int n = G.Vertex();
   bool visited[n];

   for (int i = 0; i < n; i++) {
        visited[i] = 0;
   }

   DFS(G, s, visited);
}

int GraphSearch::findComp(Graph &G) {
   int n = G.Vertex();
   bool visited[n];
   int comp = 0;

   for (int i = 0; i < n; i++) {
        visited[i] = 0;
   }

   for (int i =0; i < n; i++ )  {
        if (!visited[i]) {
            DFS(G,i,visited);
            comp++;
        }
   }

   return comp;
}



void GraphSearch::topoSort(Graph &G, int s) {

  int n = G.Vertex();
  bool visited[n];
  int topo[n];
  int curr_label = n;

  for (int i = 0; i < n; i++) {
       visited[i] = 0;
       topo[i] = -1;
  }

  for (int i = 0; i < n ; i++) {
       if (!visited[i]) {
           DFS(G, s, visited,topo, curr_label);
       }
  }

  for (int i = 0; i < n ; i++) {
    cout << i << " : " << topo[i] << endl;
  }

}

bool isCyclic(int v, Graph &G, int visited[], int completed[])

 {
     visited[v] = 1;
     cout << v << " : " << completed[v] << endl;
     for (auto i : G.adjList(v)) {
          if (!visited[i]) {
              if (isCyclic(i,G,visited,completed)) {
                  return true;
              }
          } else {
              if (!completed[i]) {
                  return true;
              }
          }
     }

     completed[v] = 1;
     return false;

 }


 //Function to detect cycle in a directed graph.
 bool isCyclic(Graph &G)

 {
     int V = G.Vertex();
     int visited[V];
     int completed[V];

     for (int i = 0; i < V; i++) {
         visited[i] = 0;
         completed[i] = 0;
     }



     for (int i = 0; i < V; i++) {
         if (!visited[i]) {
             if (isCyclic(i, G, visited, completed)) {
                 return true;
             }
         }
     }

     return false;


 }

bool isCyclic_undirected(Graph &G, int v, int visited[], int &pred) {

     visited[v] = 1;
     cout << v << " : " << pred << endl;
     for (auto i : G.adjList(v)) {
          if (!visited[i]) {
              if (isCyclic_undirected(G,i,visited,v)) {
                  return true;
              }
          } else {
              if (i != pred) {
                  return true;
              }
          }
     }

     return false;
}

bool isCyclic_undirected(Graph &G) {
     int V = G.Vertex();
     int visited[V];

     for (int i = 0; i < V; i++) {
          visited[i] = 0;
     }

     for (int i = 0; i < V; i++) {
          if (!visited[i]) {
               int pred = -1;
               if (isCyclic_undirected(G,i,visited,pred)) {
                   return true;
               }
          }
     }

     return false;
}

bool isBipartite(Graph &G, int v, int color[], int visited[], int clr) {
        visited[v] = 1;
        color[v] = clr;
        for (auto i : G.adjList(v)) {
             if (!visited[i]) {
                 if (!isBipartite(G,  i,color,visited,!clr)) {
                     return false;
                 }
             } else {
                 if (color[i] == clr) {
                     return false;
                 }
             }
        }

        return true;

   }

 bool isBipartite(Graph &G){
     // Code here
     int V = G.Vertex();
     int visited[V];
     int color[V];

       for (int i = 0; i < V; i++) {
            visited[i] = 0;
            color[i] = -1;
       }


       for (int i = 0; i < V; i++) {
           if (!visited[i]) {
               if (!isBipartite(G,i,color,visited,0)){
                   return false;
               }

           }
       }

       return true;

 }

void GraphSearch::shortestPaths(Graph &G, int src)
{
    int V = G.Vertex();
    int visited[V];
    int dist[V];
    int pred[V];

    for (int i = 0; i < V; i++) {
         visited[i] = 0;
         dist[i] = INT_MAX;
         pred[i] = -1;
    }

    GraphSearch::BFS(G,src,visited,dist,pred);
}


void DFS(Graph &G, int v, int visited[]) {

   cout << v << " " << endl;
   visited[v] = 1;
   for (auto i : G.adjList(v)) {
       if (!visited[i]) {
           DFS(G, i, visited);
       }
   }
}

void DFSOrder(Graph &G, int v, bool visited[], vector<int> &revPostOrder) {

   cout << v << " " << endl;
   visited[v] = 1;
   for (auto i : G.adjList(v)) {
       if (!visited[i]) {
           DFSOrder(G, i, visited, revPostOrder);
       }
   }

   revPostOrder.push_back(v);
}



void DFSOrder(Graph &G, int s, vector<int> &revPostOrder) {
   int n = G.Vertex();
   bool visited[n];

   for (int i = 0; i < n; i++) {
        visited[i] = 0;
   }

   DFSOrder(G, s, visited, revPostOrder);
}

void transposeGraph_inline(Graph &G)
{
     int v = G.Vertex();
     int len[v];
     int i,j;

     for (int i = 0 ; i < v; i++) {
          len[i] = G.adjList(i).size();
          cout << len[i] << endl;
     }

     for (i = 0 ; i < v; i++) {
          vector<int> *v = G.adjListRef(i);
          cout << "test" << endl;
          for (j = 0 ; j < len[i]; j++) {
               int src = v->at(j);
               printf("\nAdding edge %d %d", src , i);
               G.addEdge(src, i);
               //printf("\nErasing %d-%d", src,*(adj[i].begin()));
          }
          v->erase(v->begin(), v->begin()+j-1);
     }

     cout << "Reverse done " << endl;
}




findSCC::findSCC(Graph &G) {

    int V = G.Vertex();
    vector<int> revPostOrder;

    count = 0;
    id = new int[V];
    int visited[V];

    memset(visited,0,V);

    transposeGraph_inline(G);

    DFSOrder(G,0,revPostOrder);

    int sz = revPostOrder.size();

    for (int i = sz-1; i > 0; i--) {
      int v = revPostOrder[i];
      if (!visited[v]) {
          id[v] = count;
          DFS(G,v,visited);
      }
      count++;
    }

}


bool findSCC::stronglyConnected(int v, int w)
{
        return id[v] == id[w];
}

int main () {
  // Create a graph given in the above diagram
  bool is_directed = false;
  Graph g(8, is_directed);
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.addEdge(3, 7);
  g.addEdge(4, 6);
  g.addEdge(4, 5);
  g.addEdge(6, 7);

  GraphSearch::shortestPaths(g,0);

  //cout << "Following is Breadth First Traversal "
    //   << "(starting from vertex 2) \n";

  //GraphSearch srh1(g,0,BFS_SEARCH);
  //GraphSearch::BFS(g,2);
  //BFS(2);
  cout << endl;
  //cout << "Following is Depth First Traversal"
    //      " (starting from vertex 2) \n";
  //g.DFS(2);
  //GraphSearch srh2(g,2,DFS_SEARCH);
  //GraphSearch::DFS(g,2);


  is_directed = true;
  Graph g2(6, is_directed);
  g2.addEdge(0, 1);
  g2.addEdge(0, 2);
  g2.addEdge(1, 3);
  g2.addEdge(2, 3);
  g2.addEdge(4, 5);


  GraphSearch::BFS(g2,0);

  cout << "TopoSort:" << endl;

  GraphSearch::topoSort(g2,0);

  cout << "Finding connected Components" << endl;
  int cc = GraphSearch::findComp(g2);
  cout << "Comp Count " << cc << endl;

  Graph g5(9,true);

  g5.addEdge(8, 8);
  g5.addEdge(6, 0);
  g5.addEdge(0, 2);
  g5.addEdge(2, 4);
  g5.addEdge(4, 7);
  g5.addEdge(7, 5);
  g5.addEdge(5 ,1);
  g5.addEdge(1, 3);
  g5.addEdge(5, 6);

  Graph g3(21,true);
  g3.addEdge(10, 20);
  g3.addEdge(7, 2);
  g3.addEdge(2, 3);
  g3.addEdge(3, 1);
  g3.addEdge(1, 6);
  g3.addEdge(6, 9);
  g3.addEdge(9, 8);
  g3.addEdge(8, 5);
  g3.addEdge(5, 4);
  g3.addEdge(4, 0);
  g3.addEdge(8, 4);
  g3.addEdge(6, 8);
  g3.addEdge(7, 0);
  g3.addEdge(1, 5);
  g3.addEdge(9, 1);
  g3.addEdge(5, 1);
  g3.addEdge(1, 9);
  g3.addEdge(7, 1);
  g3.addEdge(8, 7);
  g3.addEdge(1, 8);
  g3.addEdge(2, 7);

  GraphSearch::DFS(g3,0);
  if (isCyclic(g3)) {
      cout << "Graph is cyclic" << endl;
  } else {
      cout << "Graph is acyclic" << endl;
  }


  Graph g4(13,true);
  g4.addEdge(4, 2);
  g4.addEdge(2, 3);
  g4.addEdge(3, 2);
  g4.addEdge(6, 0);
  g4.addEdge(0, 1);
  g4.addEdge(2, 0);
  g4.addEdge(11, 12);
  g4.addEdge(12, 9);
  g4.addEdge(9, 10);
  g4.addEdge(9, 11);
  g4.addEdge(7, 9);
  g4.addEdge(10, 12);
  g4.addEdge(11, 4);
  g4.addEdge(4, 3);
  g4.addEdge(3, 5);
  g4.addEdge(6, 8);
  g4.addEdge(8, 6);
  g4.addEdge(5, 4);
  g4.addEdge(0, 5);
  g4.addEdge(6, 4);
  g4.addEdge(6, 9);
  g4.addEdge(7, 6);

  //GraphSearch::BFS(g4,0);

  //findSCC scc(g4);

  //cout << "Count of components " << scc.count << endl;
  return 0;
}
