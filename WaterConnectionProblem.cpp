 vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        pair<int,int> g[n+1] ; 
        
        fill(g , g+n+1 , make_pair(-1,-1)) ; 
        
        bool in[n+1] = {0} ; 
        
        bool out[n+1] = {0} ; 
        
        for(int i = 0 ; i< p ; i++)
        {
            g[a[i]] = {b[i] , d[i]} ; 
            
            in[b[i]] = 1 ;
            out[a[i]] = 1 ;
        }
        
        queue<int> q ; 
        
        for(int i = 1 ; i <= n ; i++)
        {
            if(in[i] == 0 and out[i] == 1) q.push(i) ; 
        }
        
        vector<vector<int>> ans ; 
        
        while(q.empty() == false)
        {
            
            int u = q.front() ; 
            
            q.pop() ; 
            
            int start = u ; 
            
            int mini = INT_MAX ;
            
            while(g[u].first != -1)
            {
                mini = min(mini , g[u].second) ; 
                
                u = g[u].first ;
            }
            
            ans.push_back({start , u , mini}) ; 
        }
        
        
        return ans ; 
        
        
    }
