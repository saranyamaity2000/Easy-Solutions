public:
    long long int mod = 1e9 + 7  ; 
    long long int modadd(long long int a, long long int b) { // mod addition 
      return ((a%mod) + (b%mod)) % mod;
    }

    long long int modsub(long long int a, long long int b) { // mod substraction
      return (((a - b) % mod) + mod) % mod;
    }
    long long int  countPS(string str)
    {
       int n = str.size() ; 
       long long int mod = 1e9 + 7 ; 
       long long int dp[n][n] ; 
       memset(dp, 0 , sizeof(dp)) ; 
       for(int gap = 0 ; gap<n ; gap++){
           for(int i= 0 ; i<n-gap ; i++){
               int j = i + gap ;
               if(gap == 0) dp[i][j] = 1 ; 
               else{
                   if(str[i] == str[j])
                      dp[i][j] = modadd(1+dp[i+1][j],dp[i][j-1]) ; 
                   else 
                      dp[i][j] = modsub(modadd(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]);
               }
           }
       }
       return dp[0][n-1] ; 
    }

// if hint needed go for peepcoding explanation ! 
