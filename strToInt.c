
// function to covert string to int
int my_atoi(const char *str) {
          
    int i,val = 0, off = 0;
    
    if (str[0] == '-') {
        off = 1;
    } else {
        off = 0;
    }

    for (i = off; str[i] != '\0' ; i++) {
        val = val * 10;
        val += str[i] - '0';
    }

    if (off) {
       return (-1 * val);
    } else {
       return (val);
    } 
}


main (int argc , char *argv[]) {

   printf("value of coverted string is %d ", my_atoi(argv[1]));

}
