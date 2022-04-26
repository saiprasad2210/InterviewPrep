// Before single element all the dup elemts starts at even index 
// After single element they start at odd index
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        
        
        while (lo <= hi) {
            int mid = lo + (hi- lo)/2;
            
            if (mid-1 >=0 && arr[mid] == arr[mid-1]) {
                if (mid%2 == 1) {
                    lo = mid+1; // even start
                } else {
                    hi = mid-2; // odd start
                }
            } else if (mid+1 < n && arr[mid] == arr[mid+1]) {
                if (mid%2 == 0) {
                    lo = mid+2; // even start
                } else {
                    hi = mid-1; // odd start
                }
            } else {
                return arr[mid];
            }
        } 
        
        return -1;
    }
};
