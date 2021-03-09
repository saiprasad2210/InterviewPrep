class Solution {
public:
    
    /*
     * Check from reverse if last element is reachable from previous
     */
    
    bool jumpTest2(vector<int>& nums, int i, int t, int sz) {
        
         //cout << i <<  " " << t << endl;
         if (i < 0 || t < 0 || i > sz-1 || t > sz-1) 
             return false;
        
         if (i == 0 && nums[i] >= t-i) {
             return true;
         } 
        
         if (nums[i] >= t-i) {
                 // if t is rechable from i , t = i and i -- 
             return jumpTest2(nums, i-1, i, sz) ;
         } else {
             return jumpTest2(nums, i-1, t, sz) ;
         }      
    }
    
    bool jumpTest(vector<int>& nums, int n, int i) {
        
        //cout << i <<  " " << n<< endl;
        
        if (i > n-1 || i < 0) return false;
        if (i == n-1)         return true;
        if (nums[i] >= n-1)   return true;
        if (nums[i] <= 0)     return false;
        
        
        for (int k = nums[i]; k > 0; k--) {
            if (jumpTest(nums, n, i+k)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int t = n-1;
        
        if (n ==1) {
            return true;
        }
        
        return jumpTest2(nums,t-1,t,n);
        
    }
};
