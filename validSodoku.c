

/*
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */



bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int map_col[10],map_row[10] ,i,j,val = 0,k,x,y;
    
    //printf ("sizes %d --%d\n",boardRowSize, boardColSize);
    //validate_row()
    for (i = 0 ; i < boardColSize; i++ ) {
        
        for (k =0 ; k <10; k++) {
            map_row[k] = 0;   
        }
        //memset(map_row,0,10);
        
        for (j = 0 ; j < boardColSize; j++) {
            if (board[i][j] != '.') {
                
            val = board[i][j] - '0';
            //printf("row %c---%d --%d\n",board[i][j], val,map_row[val]  );
            if (map_row[val] == 0)  {
                map_row[val]++;
            } else {
                //printf ("Return due to invalid row");
                
                return 0;
            }
        }   
        }
    }
    
    // validate_col()
    
    for (i = 0 ; i < boardRowSize; i++ ) {
        for (k =0 ; k < 10; k++) {
            map_col[k] = 0;   
        }
         //memset(map_col,0,10);
        for (j = 0 ; j < boardColSize; j++) {
        if (board[j][i] != '.') {
            val = board[j][i] - '0'; 
             //printf("col %c---%d --%d\n",board[j][i], val, map_col[val]  );
            if (map_col[val] == 0)  {
                map_col[val]++;
            } else {
                printf ("Return due to invalid col");
                return 0;
            }
        }  
        }
        
    }
    
    
    
    for (x = 0; x <= 6; x+=3) {
        
        for (y = 0; y <= 6; y+=3){
            
            for (k =0 ; k <10; k++) {
                 map_row[k] = 0;   
            }
            for (i = x; i< x+3 ;i++) {
                for (j = y; j < y+3; j++) {
                    if (board[i][j]  != '.') {
                        val = board[i][j] - '0';
                         //printf("%d ",val);
                        if (map_row[val] == 0)  {
                            map_row[val]++;
                        } else {
                           //printf ("Return due to invalid row");
                           return 0;
                        }
                    }
                
                 }
            }
       }
    }
    return 1;
    
}

