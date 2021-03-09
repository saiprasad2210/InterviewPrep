

// String to int
main(int argc, char *argv[]) {
   int idx,key;
   //  int a[] = {1,2,3,4,5,6,7,8,9,10, 11};
   int a[] = {1, 2, 8, 10, 10, 12, 19};
   int n = sizeof(a) / sizeof(int);
}

int ceilFloor(int *arr, int key, int *ceil, int *floor) {
   int i, n;

   ceil = arr[0];
   floor = arr[0];

   for (i = 0 ; i < n ; i++) {
       if (arr[i] == val) {
           *ceil = val;
           *floor = val;
           return;
       }

       if (arr[i] > val ) {
         
           *ceil = arr[i];
       }

       if (arr[i] < val ) {
          *floor = val;
       }
   }  
}
