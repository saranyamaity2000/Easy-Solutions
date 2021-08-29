int palindromicPartition(string str){
         
        int n = str.size();
        
        fill(dp , dp + n , INT_MAX) ; // defined outside !
        
        bool P[n][n];
        memset(P , 0 , sizeof(P)) ; 
        
        int i, j, k, gap;
        
        for(gap = 0; gap < n; gap++){
            for(i = 0 ; i < n - gap ; i++){
                j = i + gap;
                if(gap == 0)
                    P[i][j] = 1; 
                else if(gap == 1)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = ((str[i] == str[j]) & P[i+1][j-1]);
            } 
        }
        
        for(i = 0;i < n;i++){
            if(P[0][i])
                dp[i] = 0;
            else{
                for(j = 0;j < i;j++){
                    // if (j+1) to i is palindrome
                    // then 1 extra is needed than dp[j]
                    if(P[j+1][i])
                        dp[i] = min(dp[i],dp[j]+1) ;
                }
            }
        }
        
        return dp[n-1];
    }


