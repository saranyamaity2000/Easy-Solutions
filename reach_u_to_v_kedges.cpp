#define mod 1000000007

int dp[51][51] ; 

class Solution {
  public:
    int minpath(vector<vector<int>>&graph, int u, int v, int k){
        
        if(dp[u][k] != -1) return dp[u][k] ; 
        
        if(k == 0) return (u == v) ; 
        
        dp[u][k] = 0 ; 
        
        for(int i = 0; i<graph.size() ; i++){
            if(graph[u][i]) dp[u][k] = (dp[u][k] + minpath(graph , i , v , k-1)) % mod ; 
        }
        
        return dp[u][k] ;
    }
    
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    memset(dp, -1, sizeof(dp)) ; 
	    minpath(graph , u , v , k) ;
	    return dp[u][k] ; 
	}

};

//problem link -> https://practice.geeksforgeeks.org/problems/possible-paths3834/1#
