#include<iostream>
#include<vector>

using namespace std;

// find latest non clonflict before n-th job
int findNext(vector<vector<int> > jobs, int n) {

    for (int i = n-1; i >=0; i--) {
         if (jobs[i][1] <= jobs[n][0]) {
             return i;
         }
    }

    return -1;
}

// sort on inc of finsih time
static bool jobComparataor(vector<int> a, vector<int> b) {
   return (a[1] < b[1]);
}

int findMaxProfit(vector<vector<int> > jobs) {
    int n = jobs.size();
    int opt[n];

    // sort on inc finish time to induce ordering
    sort(jobs.begin(), jobs.end(),jobComparataor);

    opt[0] = jobs[0][2];

    for (int i = 1; i < n; i++) {
         int inc_n;

         int t = findNext(jobs,i);
         //cout << "i: " << i << " t: " << t << " w: "<< jobs[i][2] << endl;
         if (t != -1) {
             inc_n = jobs[i][2] + opt[t];
         } else {
             inc_n = jobs[i][2];
         }
         opt[i] = max(opt[i-1], inc_n);
         //cout << "opt[i] " << opt[i]<< endl;
    }

    return opt[n-1];
}




int main () {
    //Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    //int n = sizeof(arr)/sizeof(arr[0]);
    /*(1,2,50);
    (3,10,20);
    (6,19,100);
    (2,100,200);*/

    vector<int> v1 = {3, 10, 20};
    vector<int> v2 = {1, 2, 50};
    vector<int> v3 = {6, 19, 100};
    vector<int> v4 = {2, 100, 200};


    vector<vector<int> > jobs = {v1,v2,v3,v4};

    cout <<  findMaxProfit(jobs) << endl;

}
