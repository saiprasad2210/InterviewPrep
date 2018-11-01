// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int my_bsearch(int lo, int hi);

int my_bsearch(int lo, int hi) {
    printf ("%d --- %d \n", lo, hi);
    int mid;
    
    if (lo > hi) {
        return -1;
    } 
    
    if (lo == hi) {
        return (hi);
    }
    
    
    mid = lo + (hi - lo) / 2;
    
    //printf ("mid = %d\n", mid);
    if (isBadVersion(mid)) {
        
            return (my_bsearch(lo,mid));
        
    } else {
        
            if (mid+1 <= hi && isBadVersion(mid+1)) {
                return mid+1;
            } else {
                return (my_bsearch(mid,hi));
            }
        
    }
    
    
}

int firstBadVersion(int n) {
    
    return (my_bsearch(1,n));
    
}
