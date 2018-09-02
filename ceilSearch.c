



main(int argc, char *argv[]) {
   int idx,key = atoi(argv[1]);
   int a[] = {1, 2, 8, 10, 10, 12, 19, 23, 26};
   int n = sizeof(a) / sizeof(int);
   printf("n org = %d\n",n);
   idx = ceilSearch(a, key, 0, n-1);
   if (idx >= 0)
       printf("celing of %d is %d ", key, a[idx]); 
   else 
       printf("ceiling dosent exist\n");
   
}


int ceilSearch(int *arr, int key, int l, int r) {

    int mid = 0;
    if (key  <= arr[0]) {
        return 0;
    }

    if (key > arr[r]) {
        return -1;
    }

    mid = l + (r-l) / 2 ;
    
    if (arr[mid] == key ) {
        return mid;
    } else if (arr[mid] > key ) {
        if (mid -1 >= l && arr[mid-1] < key) {
            return mid;
        } else {
            return ceilSearch(arr, key, l, mid -1);
        }    
  
    } else {
        if (mid+1 <= r && arr[mid+1] > key) {
            return mid+1;
        } else {
            return ceilSearch(arr, key,mid+1 ,r);
        }
    }
}
