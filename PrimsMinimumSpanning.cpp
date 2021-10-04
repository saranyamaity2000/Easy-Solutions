 int spanningTree(int n, vector<vector<int>> g[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>  > pq ; 
        
        pq.push({0 , 0}) ;
        
        int total = 0 ;
        
        bool vis[n] ; memset(vis , 0 , sizeof(vis)) ; 
        
        unordered_set<int> mst ; 
        
        while(pq.empty() == false)
        {
              int u = pq.top().second ; 
              int cost = pq.top().first ;
              pq.pop() ;
              
              if(vis[u]) continue ;
              
              vis[u] = true ; 
              total += cost ;
              
              mst.insert(u) ; 
              if(mst.size() == n) break ; 
              
              for(auto v_w : g[u])
              {
                  if(not vis[v_w[0]])
                  {
                      pq.push({v_w[1] , v_w[0]}) ; 
                  }
              }
        }
        
        return total ; 
    }

// EASIEST WAY ! 
