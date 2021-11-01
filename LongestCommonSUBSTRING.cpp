int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1] ;
        memset(dp,  0, sizeof(dp)) ; 
        
        // dp[i][j] stores string of len i of s1 snd string of len j of s2's longest suffix arr ; 
        
        int maxi = 0 ; 
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=m ; j++)
            {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1] ;
                maxi = max(maxi , dp[i][j]) ; 
            }
        }
        
        return maxi ; 
    }
