class Solution {
public:
    
    // Utility function to find minimum of three numbers
    int min3(int x, int y, int z)  { 
            return min(min(x, y), z); 
    }
     
    int minOp(string w1, string w2, int m, int n, vector<vector<int>> &dp) {
        
        if (m == -1) {
            return n >= 0 ? n+1 : 0;
        } 
        
        if (n == -1) {
            return m >= 0 ? m+1 : 0;
        }
        
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        
        if (w1[m] == w2[n]) {
            return minOp(w1,w2,m-1,n-1,dp);
        }
        
        dp[m][n] = 1 + min3 ( 
              minOp(w1,w2,m-1,n,dp), // delete from w1
              minOp(w1,w2,m, n-1,dp), // insert into w1
              minOp(w1,w2,m-1,n-1,dp) // replace in w1
         
        );
        
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        
        int op = minOp(word1,word2,m-1,n-1,dp);
        
        return op;
    }
};
