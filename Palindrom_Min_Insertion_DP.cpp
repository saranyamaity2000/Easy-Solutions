int findMinInsertions(string s){
        int n = s.size() ;
        int dp[n][n] ; 
        memset(dp , 0 , sizeof(dp)) ; 
        for(int gap = 0; gap<n ; gap++){
            for(int i =0 ; i<n- gap ; i++){
                int j = i + gap ; 
                if(gap == 0) dp[i][j] = 0 ; 
                else if(gap == 1) dp[i][j] = s[i] != s[j] ; 
                else {
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1] ; 
                    }else{
                        dp[i][j] = 1 + min(dp[i+1][j] , dp[i][j-1]) ; 
                    }
                }
            }
        }
        return dp[0][n-1] ; 
    }

// IT CAN ALSO BE SOLVED BY CALCULATIING LONGEST PALINDROMIC SUBSEQUECNCE
WITH THE HELP OF LCS , and then ans = Len of string - LCS(S , rev(S))
