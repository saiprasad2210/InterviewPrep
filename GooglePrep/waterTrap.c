class Solution {
public:
    
    int find_match(vector<int>& h, int i) {
        int next_block;
        
        if (i < h.size()-1) {
            next_block = i+1;
        } else {
            return -1;
        }
        
        for (int j = i+1; j < h.size(); j++ ) {
             if ( h[j]>=h[i]) {
                  return j;
             } else if (h[j] > 0 && h[j] >= h[next_block]) {
                 next_block = j;
                 
             }
        } 
        
        return next_block;
    }
    
    
    
    int trap(vector<int>& height) {
        int i = 0 ,j = 0, k=0, Ar=0;
        
        for(i = 0; i < height.size();) {
            if (height[i] > 0) {
                k = find_match(height,i);
                if (k > 0) {
                    
                    Ar += (k-i-1) * min(height[i], height[k]);
                    for (j=i+1; j<k; j++) {
                        if (height[j] > 0) {
                            Ar -= height[j];
                        }
                    }
                    //printf("i-%d k-%d Ar-%d\n",i, k,Ar);
                    i = k;
                } else {
                    i++;
                }
            } else {
                i++;
            }
                    
        }
        return Ar;
    }    
    
    
    // Solution given by leet code two pointers
    int trap2(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
};


