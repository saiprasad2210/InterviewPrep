#include "unionFind.h"


/*
 * Given a social network containing nn members and a log file containing mm timestamps at which times pairs of members formed friendships, 
 * design an algorithm to determine the earliest time at which all members are connected (i.e., every member is a friend of a friend of a friend ... of a friend).
 * Assume that the log file is sorted by timestamp and that friendship is an equivalence relation. 
 * The running time of your algorithm should be mlogn or better and use extra space proportional to n.
 */

int timeOfFullConnect(vector<vector<int>> &friendReqs, int N) {

    WeightedQuickUnionUF Set(N);

    for (auto f : friendReqs) {
         Set.Union(f[0],f[1]);
         if (Set.count() == 1) {
             // return tstamp when there is single connected component
             return f[2];
         }
    }

    return INT_MAX;

}

 int main () {

     int N = 6;
     // sorted by tstamp
     vector<vector<int>> friendReqs = {
         {3,4, 1},
         {1,2, 2},
         {5,6, 3},
         {3,6, 5},
         {1,5, 9},
         {2,6, 10},
         {3,5, 11}
     };

     cout << timeOfFullConnect(friendReqs, N) << endl;

 }