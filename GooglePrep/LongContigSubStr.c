class Solution {
public:
    int lengthOfLongestSubstring2(string s) {
        unordered_map<char,int> hmap;
        int c=0,max =0;
        
        for (int i = 0; i < s.length();) {
            if (hmap.find(s[i]) == hmap.end()) {
                hmap[s[i]] = i;
                c++;
                if ( c > max) {
                    max = c;
                }
                i++;
            } else {
                i = hmap[s[i]] + 1;
                c = 0;
                hmap.clear();
            }
            
        }
        
        return max;
        
    }
    
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hmap;
        int c=0,max =0, left =0;
        
        for (int i = 0; i < s.length(); i++) {
            if (hmap.find(s[i]) == hmap.end()) {
                hmap[s[i]] = i;
                c++;
                
            } else {
                if (hmap[s[i]] >= left) {
                    left = hmap[s[i]]+1;
                    c= i-left+1;  
                    
                } else {
                    c++;
                }   
                
                hmap[s[i]] = i;
                
                //printf("i %d left %d c %d \n",i,left, c);
            }
            
            if (c > max) {
                max = c;
            }
            
        }
        
        return max;
        
    }
};
