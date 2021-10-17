class Solution {
  vector<vector<int>> ans ; 
  vector<int> temp ; 
  vector<bool> vis ; 
  
  public:
    
    void take(vector<int> arr)
    {
        if(temp.size() == arr.size())
        {
            ans.push_back(temp) ;
            return ; 
        }
        for(int i = 0; i<arr.size() ; i++)
        {
            if(not vis[i])
            {
                if(i!=0 and not vis[i-1] and arr[i] == arr[i-1]) continue ; 
                temp.push_back(arr[i]) ;
                vis[i] = 1 ; 
                take(arr) ; 
                vis[i] = 0 ; 
                temp.pop_back() ; 
            }
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        
        ans.clear() ; 
        temp.clear() ;
        
        sort(arr.begin(), arr.end()) ;
        
        vis = vector<bool>(n,false) ; 
        
        take(arr) ; 
        
        return ans ; 
    }
};
