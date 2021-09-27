class Solution {
    
public:
    
    int denom(vector<int>& coins, int i, int a, vector<vector<int>> &d) {
        
        if ( a == 0) {
            return 0;
        }
        
        if (i < 0 || a < 0) {
            return 0;
        }
        
        if (d[i][a] != -2) {
            return d[i][a];
        }
        
        
        int t1 = -1;
        
        if (a-coins[i] >= 0) {
            t1 = denom(coins,i,a-coins[i],d);
        }
        
        int t2 = -1; 
            
        if (i > 0) {
            t2 = denom(coins,i-1,a,d);
        }
        
        if (t1 != -1 && t2 != -1) {
            d[i][a] = min(1+t1, t2);
        } else if (t1 == -1 && t2 == -1) {
            d[i][a] = -1;
        } else {
            if (t1 == -1) {
                d[i][a] = t2;
            } else {
                d[i][a] = 1+t1;
            }
        }
        
     
        
        return d[i][a];
        
        
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
          int n = coins.size();
        
          vector<vector<int>> d(n, vector<int> (amount+1, -2));
        
         return denom(coins,n-1,amount, d);
        
    }
};
