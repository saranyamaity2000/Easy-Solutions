bool isInterleave(string A, string B, string C) 
    {
        
        int n = A.size() ; 
        int m = B.size() ; 
        if( n + m != C.size()) return false ; 
        
        bool dp[n+1][m+1] ; 
        
        memset( dp , 0 , sizeof(dp)) ; 
        
        dp[0][0] = 1 ; 
        
        for(int i = 1 ; i <= n ; i++)
        {
            if(A[i-1] == C[i-1]) dp[i][0] = dp[i-1][0] ; 
        }
        
        for(int i = 1 ; i <= m ; i++)
        {
            if(B[i-1] == C[i-1]) dp[0][i] = dp[0][i-1] ; 
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=m ; j++)
            {
               if(A[i-1] == C[i+j-1]) dp[i][j] |= dp[i-1][j] ; 
               if(B[j-1] == C[i+j-1]) dp[i][j] |= dp[i][j-1] ; 
            }
        }
        
        
        return dp[n][m] ; 
    }
