#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
   int V;
   int E;
   vector<int> *adj;

public:
   Graph (void);
   void DFS(int start, bool is_rev);
   void DFSUtil(int v, bool visited[], bool is_rev);
   void addEdge(int v, int w);
   void find_SCC(vector<int> &scc);
};

void Graph::addEdge(int v, int w) {
      adj[v].push_back(w);
      //cout << v << " " << w << endl;
}

void Graph::DFSUtil(int v, bool visited[], bool is_rev) {

   //cout << v << " " << endl;
   visited[v] = 1;
   for (auto i :adj[v]) {
       if (!visited[i]) {
           DFSUtil(i,visited,is_rev);
       }
   }

}

void Graph::DFS(int s, bool is_rev) {
   bool visited[V];

   for (int i = 0; i < V; i++) {
        visited[i] = 0;
   }

   DFSUtil(s, visited,is_rev);
}

Graph::Graph(void) {
   ifstream fstr;
   int lines,v_count = 0,e_count = 0,a,b;

        FILE *fp;
        fp = fopen("gdata", "r");

                while ( !feof(fp))
                {
                        int a,b;
                        fscanf(fp, "%d %d",&a, &b);
                        //printf("%d %d\n", a,b);
                        if (a > v_count) {
                            v_count = a;
                        } else if (b > v_count) {
                            v_count = b;
                        }
                        e_count++;

                }
                fclose(fp);
   /*
   string line;
   fstr.open("graph.txt");
   fstr >> lines;
   cout << lines << endl;
   while (std::getline(fstr,line)) {
      fstr >> a >> b;
      //cout << a << " " << b << endl;
      //addEdge(a,b);
      if (a > v_count) {
         v_count = a;
      } else if (b > v_count) {
         v_count = b;
      }
      e_count++;
   }

   */

   cout << e_count << endl;

   V = v_count;
   E = e_count;
   //cout << "V: " << V << endl;
   adj = new vector<int>[V+1];
   fp = fopen("gdata", "r");
   e_count--;
   while ( !feof(fp) && e_count)
   {
      int a,b;
      fscanf(fp, "%d %d",&a, &b);
      printf("%d %d\n", a,b);
      addEdge(a,b);
      e_count--; 
   }

   fclose(fp);

}

int main () {
  Graph g;
  g.DFS(2,false);
}
