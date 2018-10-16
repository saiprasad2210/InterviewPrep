
/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */
void moveZeroes(int* a, int numsSize) {
    int z = 0, nz = 0, n = numsSize,t;
    
    while (z < n && nz < n) {
         while(a[z] != 0 && z < n) {
               z++;
         }
   
         while(a[nz] == 0 && nz < n) {
               nz++;
         }
        
         if (nz >= n || z >= n)
             break;

         if (nz > z) {
             t = a[nz];
             a[nz] = a[z];
             a[z] = t;
         } else {
             nz++;
         }
    }
        
}
