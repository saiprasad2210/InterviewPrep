
// Returns index of the element if found else -1
int search(int *arr , int val, int l, int r) {
    
    if (l  > r ) 
        return -1;

    //int mid = (l + r) / 2;
    int mid = l + (r - l) / 2;  
    if (arr[mid] == val) {
        return mid;
    } else if (val < arr[mid]) {
        return search(arr, val, l, mid-1);
    } else {
        return search(arr, val, mid+1, r); 
    }
}       

int search2(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 0 )
    {
        m = l + (r-l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    if( A[l] == key )
        return l;
    else
        return -1;
}
   
int itr_search (int *arr , int val, int l, int r) {
    int mid;
    while (l <= r ) {
        mid = l + (r - l) / 2;
        if (arr[mid] == val) {
            return mid;
        } else if (val < arr[mid]) {
            r  = mid -1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
} 

// function to covert string to int
int my_atoi(const char *str) {
    
    int i,val = 0, off = 0;
    if (str[0] == '-') {
        off = -1;
    }
        
    for (i = 0; str[i] != '\0' ; i++) {
        val = val * 10;
        val += str[i] - '0'; 
    }
    return val;    
}

// String to int
main(int argc, char *argv[]) {
   int idx,key;
   int a[] = {1,2,3,4,5,6,7,8,9,10, 11};
   int n = sizeof(a) / sizeof(int);
   //   key = (char)argv[1][0] - '0';
   key = my_atoi(argv[1]); 
   printf("key passed is %d\n", key);
   //idx = search(a,key,6,n-1);
   idx = search2(a,0,1,key);
   printf("%d", idx);
}
