

main(int argc, char *argv[]) {
   int lidx,ridx,key = atoi(argv[1]);
   int a[] = {1, 8, 3, 10, 10, 10, 10, 10, 26};
   int n = sizeof(a) / sizeof(int);
   printf("n org = %d\n",n);
   ridx = right_most_index(a, key, 0, n-1);
   if (ridx >= 0)
       printf("rightmost occurence of  %d is %d \n", key, ridx);
   else
       printf("right most occurence for %d dosent exist\n", key);

   lidx = left_most_index(a, key, 0, n-1);
   if (lidx >= 0)
       printf("lefmost occurence of  %d is %d \n", key, lidx);
   else
       printf("left most occurence for %d dosent exist\n", key);

   printf("Total number of occurences for key %d is %d\n", key, (ridx == lidx && ridx != -1 ) ? 1 : ridx-lidx);

}

int right_most_index (int *arr, int key, int lo , int hi) {

   int mid,idx;

   if (lo > hi)
      return -1;

   mid = (lo + hi) / 2;

   if (arr[mid] == key ) {
       if (mid == hi) {
           return mid;
       } else if (mid + 1 <= hi && arr[mid+1] != key)
           return mid;
       else 
           return right_most_index(arr, key, mid+1, hi);

   } else if (key < arr[mid]) {
       return right_most_index(arr,key, lo, mid-1);
   } else {
       return right_most_index(arr,key, mid+1,hi); 
   }

}

int left_most_index (int *arr, int key, int lo , int hi) {
   int mid,idx;

   if (lo > hi)
      return -1;

   mid = (lo + hi) / 2;

   if (arr[mid] == key ) {
       if (mid == lo) {
           return mid;
       } else if (mid - 1 >= lo && arr[mid-1] != key)
           return mid-1;
       else
           return left_most_index(arr, key, lo,  mid-1);

   } else if (key < arr[mid]) {
       return left_most_index(arr,key, lo, mid-1);
   } else {
       return left_most_index(arr,key, mid+1,hi);
   }

}
