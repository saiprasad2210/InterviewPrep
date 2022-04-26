#include<iostream>

using namespace std;

#define boolean bool

boolean isMazePathExists(vector<vector<int> > &Maze, pair<int, int> &curr, pair<int, int>&dest , int &count) {

       if (curr == dest) {
           count++;
           return true;
       }

       if (curr.first < 0 || curr.first > Maze.size()-1 ||
           curr.second < 0 || curr.second > Maze.size()-1) {
           return false;
       }

       if (Maze[curr.first][curr.second] == -1) {
           return false;
       }

       pair<int ,int> next1(curr.first+1, curr.second);
       pair<int ,int> next2(curr.first,   curr.second+1);

       /*
       if (isMazePathExists(Maze,next1,dest) || isMazePathExists(Maze,next2,dest)) {
           return true;
       }*/

       boolean a = isMazePathExists(Maze,next1,dest,count);
       boolean b = isMazePathExists(Maze,next2,dest,count);

       if (a || b) {
           return true;
       }

       return false;
}

int main () {
  int count = 0;
  vector<vector<int> > Maze;

  vector<int> vect({10, 20, 30});
  vector<int> v1({0,  0, 0, 0});
        vector<int> v2{0, -1, 0, 0};
            vector<int> v3{-1, 0, 0, 0};
                vector<int> v4{0,  0, 0, 0};

  vector<vector<int> > Maze{v1,v2,v3,v4};

  pair<int,int> src(0,0);
  pair<int,int> dst(Maze.size()-1,Maze.size()-1);

  boolean a = isMazePathExists(Maze,src,dst,count);

  if (a)
     cout << "Count " << count << endl;
  else
     cout << "Path dosent exists" << endl;
}
