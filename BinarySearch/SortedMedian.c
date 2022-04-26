#include <iostream>
#include<vector>

using namespace std;


float sortedMedian(vector<int> &a, vector<int> &b) {
     int X = a.size();
     int Y = b.size();

     int n = X + Y;

     int lo = 0;
     int hi = X-1;

     

     while (true) {
          //cout << lo << "<-lo-hi->" << hi << endl;

          int px = lo >= 0 ? (hi+lo)/2 : -1;
          int py = (X+Y+1)/2 - (px+2);

          //cout << px << "<-Px-Py->" << py << endl;

          int maxLeftPx  = (px < 0) ? INT_MIN: a[px];
          int minRightPx = (px == X-1) ? INT_MAX: a[px+1];

          //cout << maxLeftPx << "<-lpx-rpx->" << minRightPx << endl;

          int maxLeftPy  = (py < 0) ? INT_MIN: b[py];
          int minRightPy = (py == Y-1) ? INT_MAX: b[py+1];

          //cout << maxLeftPy << "<-lpy-rpy->" << minRightPy << endl;

          if (maxLeftPx <= minRightPy && maxLeftPy <= minRightPx) {
               int m2 = min(minRightPx, minRightPy);
               int m1 = max(maxLeftPx,  maxLeftPy);

               if (n % 2 == 0) {
                   return (float)(m1+m2)/2;
               }

               return m1;

          } else if (maxLeftPx > minRightPy) {
               
               hi = px-1;
          } else {
               lo = px+1;
          }

     }

     return -10;
     
}


int main() {
     vector<int> a = {1,3,8,9,15};
     vector<int> b = {7,11,18,19,21,25};

     //cout << sortedMedian(a,b) << endl;

     vector<int> a1 = {23,26,31,35};
     vector<int> b1 = {3,5,7,9,11,16};
     //cout << sortedMedian(a1,b1) << endl;

     vector<int> a2 = {1,3,8,9,9};
     vector<int> b2 = {10,11,18,19,21,25};

     //cout << sortedMedian(a2,b2) << endl;

     vector<int> a3 = {1,3};
     vector<int> b3 = {2};
     cout << sortedMedian(a3,b3) << endl;
}