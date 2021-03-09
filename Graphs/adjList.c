#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
  int V;
  vector<int> *adj;

  void DFSUtil(int v, bool visited[]);

  public:
     Graph(int V);  // Constructor

     // function to add an edge to graph
     void addEdge(int v, int w);

     // prints BFS traversal from a given source s
     void BFS(int s);
     
     void DFS(int s);

};

Graph::Graph(int v) {
  V = v;
  adj = new vector<int>[V];

}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::BFS(int s)
{
   queue<int> q;
   int node;
   int visited[V];
   for (int i = 0; i < V; i++) {
        visited[i] = 0;
   }

   q.push(s);
   visited[s] = 1;
   while (!q.empty()) {
      node = q.front();
      cout << node << " ";
      q.pop();
     
      for (auto i: adj[node]) {
        if (visited[i] == 0) {
             q.push(i);
             visited[i] = 1;
        }
      }
   }

   cout << endl;
}

void Graph::DFSUtil(int v, bool visited[]) {
   
   cout << v << " " << endl;
   visited[v] = 1;
   for (auto i :adj[v]) {
       if (!visited[i]) {
           DFSUtil(i,visited);
       }
   }
   
}
void Graph::DFS(int s) {
   bool visited[V];

   for (int i = 0; i < V; i++) {
        visited[i] = 0;
   }


   DFSUtil(s, visited);
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout << endl;
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2);
    return 0;
}   
