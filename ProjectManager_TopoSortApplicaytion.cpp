https://practice.geeksforgeeks.org/problems/6b216f3d1f1ce9a14258b982d44f5e5199e7759a/1#

int minTime(vector<pair<int, int>> &dep, int dur[], int n, int m) {
        
        int indeg[n]  = {0} ;
        int outdeg[n] = {0} ;
        
        vector<int> g[n] ; 
        
        for(int i = 0 ; i<m ; i++)
        {
            g[dep[i].first].push_back(dep[i].second) ; 
            indeg[dep[i].second]++ ; 
            outdeg[dep[i].first]++ ; 
        }
        
        int mintime[n] = {0} ;
        
        queue<int> q ; 
        
        for(int i = 0 ; i<n ; i++)
        {
            if(indeg[i] == 0)
            {
                mintime[i] = 0 ; 
                q.push(i) ; 
            }
        }
        
        while(not q.empty())
        {
            int u = q.front() ; 
            q.pop() ;
            
            for(int v : g[u])
            {
                mintime[v] = max(mintime[v] , mintime[u] + dur[u]) ;
                indeg[v]-- ; 
                if(indeg[v] == 0) q.push(v) ; 
            }
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            if(indeg[i]) return -1 ; 
        }
        
        int ans = INT_MIN ; 
        
        for(int i = 0 ; i<n ; i++)
        {
            if(outdeg[i] == 0) ans = max(ans , mintime[i] + dur[i]) ; 
        }
        
        return ans ; 
    }
