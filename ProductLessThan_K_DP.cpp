const int siz = 1e6 + 1 ; 

int dp[31][siz] ; 

class Solution {
  public:
    int numOfSubsets(int arr[], int n, int k) {
        
    memset(dp, 0 , sizeof(dp)) ; 
    
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=k ;j++){
            if(arr[i-1]<=j){
              dp[i][j] = 1 + dp[i-1][j] + dp[i-1][j/arr[i-1]];
            }
            else{
              dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][k];
    }
};

// NOT GOOD when K !>> N , like K = 100 N = 100 ;
