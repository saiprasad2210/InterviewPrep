#ifndef __UTILS_H__
#define __UTILS_H__

using namespace std;

typedef enum search_type {
  BFS_SEARCH,
  DFS_SEARCH
} search_type_t;


class Graph {
  int V;
  int E;
  bool is_directed;
  vector<int> *adj;

  public:
     Graph(int V, bool is_dir);  // Constructor

     // function to add an edge to graph
     void addEdge(int v, int w);

     int Vertex();
     int Edges();

     vector<int> adjList(int v);
     vector<int>* adjListRef(int v);
};


class GraphSearch {
  private:
     static void DFS(Graph &G, int v, bool visited[]);
     static void DFS(Graph &G, int v, bool visited[], int topo[], int &curr_label);
     static void BFS(Graph &G, int s, int visited[], int dist[], int pred[]);

  public:
     GraphSearch(Graph &G, int s, search_type_t stype);
     static void BFS(Graph &G,int s);
     static void DFS(Graph &G,int s);

     static void topoSort(Graph &G, int s);
     static int findComp(Graph &G);
     static void shortestPaths(Graph &G, int s);
};

//Kosaraju SCC algo
class findSCC {



  public:

      int *id;
      int count;
      findSCC(Graph &G);
      bool stronglyConnected(int v, int w);
};

#endif
