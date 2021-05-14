#include<iostream>
using namespace std;
int recSum(int sum) {
    int s = 0;
    
    while(sum  > 0) {
         s += sum % 10;
         sum = sum/ 10;
         if (sum -9 > 0) {
             sum = s;
             s = 0;
         }
    }
    
    return s;
}

int main () {
    int n = 123456789;
    int s = recSum(n);
    cout << s << endl;

}
