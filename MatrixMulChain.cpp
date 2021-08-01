//ITERATIVE WAY ! 
for(int i = 0 ; i<n ; i++){
             if(i<n-1)
             dp[i][i+1] = 0 ; 
         }
         for(int gap = 2 ; gap<n ; gap++){
             for(int i = 0 ; i<n-gap ; i++){
                 int j = i + gap ; 
                 dp[i][j] = INT_MAX ; 
                 for(int k = i+1 ; k<j ; k++){
                     dp[i][j] = min( dp[i][j] , arr[i]*arr[k]*arr[j] + dp[i][k] + dp[k][j] ) ; 
                 }
             }
         }        
 return dp[0][n-1] ;

//RECURSIVE WAY ! 

//int recur(int *arr , int i , int j){
    //     if(dp[i][j] != -1) return dp[i][j] ; 
    
    //     if(j-i == 1){
    //       return dp[i][j] = 0; 
    //     }
       
    //     dp[i][j] = INT_MAX ; 
    //     for(int k = i+1 ; k < j ; k++) {
    //       dp[i][j] = min( dp[i][j] , recur(arr , i , k) + recur(arr , k , j)  + arr[i]*arr[k]*arr[j] ) ; 
    //     }
    //     return dp[i][j] ; 
    // }

 

