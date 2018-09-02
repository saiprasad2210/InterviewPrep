

int main(int argc, char *argv[]) {
int a[] = {11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int b[] = {3, 5, 6, 7, 8, 9, 10, 11, 1, 2};
int c[] = {5, 6, 7, 1, 2, 3, 4};
int idx, key = atoi(argv[1]);

//idx = bsearch_min_rot_arr(b,0,9);
//printf("Min element is %d at index %d", b[idx], idx);

idx = bsearch_rot_arr(c, 0, (sizeof(c)/sizeof(int))-1 ,key);

printf("key is located at idx %d\n", idx); 
}


int bsearch_min_rot_arr(int *arr, int lo, int hi) {

    int mid;

    mid = (lo + hi )  / 2 ;

    if (mid == hi && arr[mid] < arr[mid-1]) {
        return mid;
    } else if (mid-1 >= lo && arr[mid] < arr[mid-1]) {
        return mid;
    } else if (mid+1 <= hi && arr[mid] > arr[mid+1]) {
        return mid+1;
    } else if (arr[mid] <= arr[lo]) {
        return bsearch_min_rot_arr(arr, lo, mid-1);
    } else if (arr[mid] >= arr[hi]) {
        return bsearch_min_rot_arr(arr, mid+1, hi);
    }

}

int bsearch_rot_arr(int *arr, int lo, int hi, int key) {
    int mid;

    mid = (lo + hi) / 2;

    if (lo > hi) 
        return -1;

    if (arr[mid] == key) {
        return mid;
    } else if (key < arr[mid]) {
        if (key < arr[lo]) {
            bsearch_rot_arr(arr, mid+1, hi, key);
        } else {
            bsearch_rot_arr(arr, lo, mid-1, key);
        }
    } else {
        if (key > arr[hi]) 
           bsearch_rot_arr(arr, lo, mid-1, key);
        else 
           bsearch_rot_arr(arr, mid+1, hi, key);
    } 
}    
