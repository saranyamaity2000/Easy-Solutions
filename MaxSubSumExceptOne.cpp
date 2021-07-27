
// This is my own approach so PLEASE star if you like it , 

 int maxSumSubarray(int A[], int n)
    {
    
      if(n == 1) return A[0] ; 
       
      int dp[n][2] ; 
      // 2nd dimension is about if already 1 element rejected or not ;
      //dp[i][0] takes care of Subarray sum without elemination
      // considering/ including ith element  
 
      //dp[i][1] takes care of Subarray sum with elemination 
      // considering/including ith element 

      dp[0][0] =  A[0] ; 
      dp[0][1] = A[0] ; 
       
      int maxi = A[0] ; 
       
      for(int i = 1 ; i<n ; i++){
          
            dp[i][0] = max( A[i] + dp[i-1][0] , A[i]) ; 
            
            dp[i][1] = A[i] + dp[i-1][1]; 
            
            if(i>=2) dp[i][1] = max( dp[i][1], dp[i-2][0] + A[i] ) ; 
            
            maxi = max( { maxi , dp[i][0] , dp[i][1]} ) ; 
            
      }
      
      return maxi ; 
    }


