 int maxProfit(int k, int n, int price[]) {
        int dp[k+1][n+1] ; 
        memset(dp , 0 , sizeof(dp)) ; 
     
        for(int t = 1 ; t<=k ; t++){
            int maxi = INT_MIN ; 
            for(int d = 2 ; d<=n ; d++){
                maxi = max(maxi , dp[t-1][d-1] - price[d-2]) ; 
                dp[t][d] = max(dp[t][d-1], maxi + price[d-1]) ;
            }
        }
        return dp[k][n] ; 
    }
