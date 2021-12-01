public:
    
     using ll = int ; 
    
    bool safe(ll i , ll j , ll n , ll m){
         return (i>=0 and j>=0 and i<n and j<m) ; 
    }
    
    int orangesRotting(vector<vector<int>>& mat) {
        
       
        
        queue<pair<ll,ll>> q ; 
        
        ll n = mat.size() , m = mat[0].size() ; 
        for(ll i = 0 ; i<n ; i++){
            for(ll j = 0; j<m ; j++){
                if(mat[i][j] == 2){
                    q.push({i,j}) ;
                }
            }
        }
        
        ll timer = -1 ; 
        
        while(q.empty() == false){
            ll l = q.size() ; 
            if(l) timer++ ; 
            else break ;
            for(ll k = 0 ; k<l ; k++){
                ll i_ = q.front().first ; 
                ll j_ = q.front().second ; 
                q.pop() ; 
                if(safe(i_+1,j_,n,m) and mat[i_+1][j_] == 1) { mat[i_+1][j_] = 2 ; q.push({i_+1,j_}) ; }
                if(safe(i_,j_+1,n,m) and mat[i_][j_+1] == 1) { mat[i_][j_+1] = 2 ; q.push({i_,j_+1}) ; }
                if(safe(i_-1,j_,n,m) and mat[i_-1][j_] == 1) { mat[i_-1][j_] = 2 ; q.push({i_-1,j_}) ; }
                if(safe(i_,j_-1,n,m) and mat[i_][j_-1] == 1) { mat[i_][j_-1] = 2 ; q.push({i_,j_-1}) ; }
            }
        }
        
        for(ll i = 0 ; i<n ; i++){
            for(ll j = 0; j<m ; j++){
                if(mat[i][j] == 1){
                    return -1 ; 
                }
            }
        }
        
        return timer ;  
        
    }

link -> https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

