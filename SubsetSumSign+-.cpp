// defined outside class 
map<pair<int,int>,int> dp ; 
vector<int> val ;

class Solution {
  
  public:
    
    int find_sum(int n, int sum)
    {
        if(dp.find({n,sum}) != dp.end()) return dp[{n,sum}] ; 
        
        if(n == 0)
        {
            if(sum == 0) return 1 ; 
            else return 0 ; 
        }
        
        return dp[{n,sum}] = find_sum(n-1 , sum + val[n-1]) + find_sum(n-1 , sum - val[n-1]) ; 
        
    }
  
    int findTargetSumWays(vector<int>& a ,int sum) {
        
        dp.clear() ; 
        
        val = a ; 
        
        int n = a.size() ; 
        
        return find_sum(n , sum) ; 
        
    }
