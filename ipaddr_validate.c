#include<stdio.h>
#include<string.h>

#define true 1
#define false 0

#define MAX_LEN 15
#define MIN_LEN 7

int is_valid_ip (char *ptr) {

    int len = 0;
    int dot_count = 0, num_count = 0;
    int num = 0;

    int i =0;

    printf("%s\n", ptr);
    len = strlen(ptr);
 
    if (len > MAX_LEN || len < MIN_LEN) {
        return false;
    } 

    // Check if it contains anything other than digits or .
    
    for (i = 0; i< len; i++ ) {
        if (ptr[i] != '.' && !(ptr[i] >= '0' && ptr[i] <= '9')) {
           return false;
        }
       
        if (ptr[i] == '.')
           dot_count++;
           
    }

    if (dot_count != 3 )
        return false;
 
    // Returns first token
    char* token = strtok(ptr, "."); 

    while (token != NULL) {
         
        num_count++;


        num = atoi(token);
       
        // Validate the parsed number
        if (!(num >=0 && num <=255)) {
            return false;
        }

        token = strtok(NULL, ".");
    }

    if (num_count != 4)
        return false;

    return true;

}


main(int argc , char *argv[]) {
   char ip1[] = "127.0.0.1";
   char ip2[] = "192.168.100.200";
   char ip3[] = "1.2.3.4";

   
   printf("%s\n", argv[1]);
   if (is_valid_ip(argv[1]) == 1)  { 
       printf("ip %s is valid", argv[1]);
   } else {
       printf("ip %s is invalid", argv[1]);
   }  
}
