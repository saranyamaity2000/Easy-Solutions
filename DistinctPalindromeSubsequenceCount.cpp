#include<bits/stdc++.h>

using namespace std ; 

#define ff first
#define ss second

int main(){
    
    string s ; 
    
    cin>> s; 
    
    int n = s.size() ; 
    
    unordered_map<char,vector<int>> pos ; 
    unordered_map<int,int> next , prev ; 
    
    for(int i = 0 ; i<n ; i++){
        pos[s[i]].push_back(i) ; 
    }
    
    for(auto pr : pos){
        
        int n = pr.ss.size() ; 
        
        for(int i = 0 ; i<n ; i++){
            next[pr.ss[i]] = pr.ss[i+1] ; 
        }
        
        for(int i = n-1 ; i>=0 ; i--){
            prev[pr.ss[i]] = pr.ss[i-1] ;
        }
    }
    
    int dp[n][n];
    memset(dp, 0 , sizeof(dp)) ; 
    
    for(int g = 0 ; g<n ; g++){
        for(int i = 0 ; i<n-g; i++){
            int j =i+g ; 
            if(g == 0) dp[i][j] = 1 ; 
            else if(g == 1 ) dp[i][j] = 2 ; 
            else 
            {
              if(s[i] != s[j]) 
                  dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
              else 
              {
                  if(next[i] == j)
                  {
                      dp[i][j] = 2*dp[i+1][j-1] + 2 ; 
                  }
                  else if(next[i] == prev[j])
                  {
                      dp[i][j] = 2*dp[i+1][j-1] + 1 ; 
                  }
                  else
                  {
                      dp[i][j] = 2*dp[i+1][j-1] - dp[next[i]+1][prev[j]-1] ; 
                  }
              }
            }
        }
    }
    
    cout<<dp[0][n-1] ; 
    
    return 0 ; 
}

// Process Learned
