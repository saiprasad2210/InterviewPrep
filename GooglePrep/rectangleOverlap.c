class Solution {
public:
    
        bool isNotOverlap(vector<int>& rec1, vector<int>& rec2) {
             
             int x11,x12,x21,x22;
             int y11,y12,y21,y22;
             int l1,l2, b1,b2;
            
             x11 = rec1[0];
             x12 = rec1[2];
             y11 = rec1[1];
             y12 = rec1[3];
            
             x21 = rec2[0];
             x22 = rec2[2];
             y21 = rec2[1];
             y22 = rec2[3];
            
            // Area is 0
             l2 = x22-x21;
             b2 = y22-y21;
             l1 = x12-x11;
             b1 = y12-y11;
            
             
             // Check if area is 0 for any input rectangle
             if (!l1 || !b1 || !l2 || !b2) {
                 
                 return true;
             }
            
             if ((x21 >= x12)|| (y21 >= y12)) {
        
                 return true;
             }
            
             if ((x22 <= x11) || (y22 <= y11)) {
                 
                 return true;
             }
             
             return false;
            
        }
             
     
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
         
          if (isNotOverlap(rec1,rec2)) {
              return false;  
          }
        
          return true;
    }
};
