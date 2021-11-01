string longestSubstring(string s, int n) {
       
       int dp[n+1][n+1] ; 
       memset(dp , 0 , sizeof(dp)) ;
       
       int start = -1 ;
       int l = 0 ; 
       
       for( int i = 1 ;i<=n ; i++)
       {
            for(int j = 1 ; j<= n ; j++)
            {
                if(s[i-1] == s[j-1] and (j-i) > dp[i-1][j-1]) dp[i][j]  = 1 + dp[i-1][j-1] ;
                
                if(dp[i][j] > l)
                {
                   l = dp[i][j] ; 
                   start = i-l ;  
                }
            }
       }
       
       if(start == -1) return "-1" ; 
       return s.substr(start,l) ; 
       
    }
