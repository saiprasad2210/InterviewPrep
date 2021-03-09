#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adj[], int src, int dst) {
     adj[src].push_back(dst);
}

void displayGraph(vector<int> adj[], int v)  {
     for (int i = 0; i < v ; i++) {
          cout << i << "--> ";
          for (int j = 0 ; j < adj[i].size(); j++) {
              cout << adj[i][j] << " " ;
          }
          cout << endl;
     }
}

void transposeGraph(vector<int> *adj,  vector<int> transpose[], int v)
{
     for (int i = 0 ; i < v; i++) {
          for (int j = 0 ; j < adj[i].size(); j++) {
               addEdge(transpose, adj[i][j], i);
          }
     }
}

void transposeGraph_inline(vector<int> adj[],  int v)
{
     int len[v];
     int i,j;

     for (int i = 0 ; i < v; i++) {
          len[i] = adj[i].size();
          //cout << len[i] << endl;
     }

     for (i = 0 ; i < v; i++) {
          for (j = 0 ; j < len[i]; j++) {
               int src = adj[i][j];
               printf("\nAdding edge %d %d", src , i);
               addEdge(adj, src, i);
               //printf("\nErasing %d-%d", src,*(adj[i].begin()));

          }

          adj[i].erase(adj[i].begin(), adj[i].begin()+j-1);
     }
}

void BFS(vector<int> adj[],  int v, int start)
{
  int visited[v];
  int ver;
  queue<int> q;

  for (int i = 0; i < v; i++ ) {
       visited[i] = 0;
  }

  visited[start] = true;
  q.push(start);

  while(!q.empty()) {
       ver = q.front();

       q.pop();

       cout << ver << " ";
       for (auto it = adj[ver].begin(); it != adj[ver].end(); it++) {
            if (!visited[*it]) {
                 visited[*it] = true;
                 q.push(*it);
            }
       }
  }

  cout << endl;

}

bool isCyclicGraphUtil(vector<int> adj[], int start, int *visited, int *inProgress ) {

        visited[start] = true;
        inProgress[start] = true;
        int ver;

        for (auto it = adj[start].begin(); it != adj[start].end(); it++) {
             ver = *it;

             if (visited[ver] && inProgress[ver]) {
                 return true;
             }

             if (!visited[ver]) {
                  return (isCyclicGraphUtil(adj,ver,visited,inProgress));
             }
        }

        inProgress[start] = false;
}

bool isCyclicGraph(vector<int> adj[],  int v, int start) {
      int visited[v];
      int inProgress[v];

      for (int i = 0; i < v; i++ ) {
           visited[i] = 0;
      }

      for (int i = 0; i < v; i++ ) {
           inProgress[i] = 0;
      }

      return (isCyclicGraphUtil(adj, start, visited, inProgress ));


}
void DFS_util(vector<int> adj[], int start, int *visited) {

  int ver;

  visited[start] = true;
  cout << start << " ";

  for (auto it = adj[start].begin(); it != adj[start].end(); it++) {
       ver = *it;
       if (!visited[ver]) {
            DFS_util(adj,ver,visited);
       }
  }

}
void DFS(vector<int> adj[],  int v, int start)
{
    int visited[v];

    for (int i = 0; i < v; i++ ) {
         visited[i] = 0;
    }

    DFS_util(adj,start,visited);

}
int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);


    //displayGraph(adj, v);
    // Finding transpose of graph represented
    // by adjacency list adj[]
    //vector<int> transpose[v];
    //transposeGraph(adj, transpose, v);
    //transposeGraph_inline(adj, v);
    // displaying adjacency list of transpose
    // graph i.e. b
    //cout << "Graph after transpose" << endl;
    //displayGraph(adj, v);
    DFS(adj,v,0);
    return 0;
}
