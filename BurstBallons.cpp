class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() ; 
        
        int dp[n][n] ; memset(dp, -1 , sizeof(dp)) ; 
        for(int i = 0 ; i<n ; i++){
            dp[i][i] = (i-1>=0? nums[i-1]:1) * nums[i] * (i+1<=n-1?nums[i+1]:1) ;
        }
        
        for(int gap = 1 ; gap<n ; gap++){
            for(int i = 0 ; i<n-gap ; i++){
                int j = i + gap ; 
                for(int curr = i ; curr<=j ; curr++){
                    int last_poped = (i-1>=0? nums[i-1]:1) * nums[curr] * (j+1<=n-1? nums[j+1]:1) ; 
                    int left_poped = (curr == i ? 0 : dp[i][curr-1]) ;
                    int right_poped = ( curr == j ? 0 : dp[curr+1][j]) ;
                    dp[i][j] = max(dp[i][j], left_poped + right_poped + last_poped ) ; 
                }
            }
        }
        
        return dp[0][n-1] ; 
    }

// CONCEPT EXLAINED WELL IN PEPCODING 
