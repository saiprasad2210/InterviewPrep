#include<iostream>
#include<string>

using namespace std;

string firstSmallest(int S, int D){
        // code here
        string out;

        if (S > D *9 ) {
            return "-1";
        }

        for (int i = 0; i < D ; i++) {

            int k = S- (D-(i+1))*9;
            if (i == 0 && k <=0 ) {
                k = 1;
            } else if (k <=0 ){
                k = 0;
            }

            out.push_back( k + '0');

            cout << S << " " << i << " -- " << out[i] << endl;

            S = S-(out[i]-'0');

        }

        //cout << out << endl;
        return out;
}

string secondSmallest(int S, int D){

     if (S > D *9 ) {
         return "-1";
     }

     string O1 = firstSmallest(S,D);

     cout << "First: " << O1 << endl;

     int S2 = S;

     S = S- (O1[O1.size()-1]-'0');

     for (int i = O1.size()-2; i >= 0; i--) {

          if (O1[i]-'0' < 9) {

              O1[i] = O1[i] + 1;

              S = S+1;

              cout << S << " " << D-(i+1) << endl;

              string O2 = firstSmallest(S2-S, D-(i+1));

              cout << "Second: " << O2  << " " << O1[i] << endl;

              for (int j = i+1,k = 0; j < O1.size(); j++) {
                   cout << j << endl;
                   O1[j] = O2[k];
                   k++;
              }

              return O1;
          }

          S = S - (O1[i] - '0');
     }

     return "-1";

}

int main(int argc, char *argv[]) {

       int S = atoi(argv[1]);
       int D = atoi(argv[2]);

       cout << secondSmallest(S,D) << endl;
}
