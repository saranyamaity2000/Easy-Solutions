bool isPossible(int n, vector<pair<int, int> >& pre) {
	    
	     int indeg[n] = {0} ; 
	     vector<int> graph[n] ;  
	     for(int i = 0 ; i<pre.size() ; i++){
	         graph[pre[i].first].push_back(pre[i].second) ; 
	         indeg[pre[i].second]++ ; 
	     }
	     
	     queue<int> q ; 
	     for(int i = 0 ; i<n ; i++){
	         if(indeg[i] == 0) q.push(i) ; 
	     }
	     while(!q.empty()){
	         int u = q.front() ; 
	         q.pop() ; 
	         for(auto v : graph[u]){
	             indeg[v]-- ; 
	             if(indeg[v] == 0) q.push(v) ; 
	         }
	     }
	     bool ok = true ; 
	     for(int i = 0 ; i<n ; i++){
	         if(indeg[i]) return false ; 
	     }
	     return true ; 
	     
	}

// MY OWN METHOD :) 
