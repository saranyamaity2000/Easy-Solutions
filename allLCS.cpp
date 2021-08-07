 int dp[101][101] ; 
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n = s.size() , m = t.size() ; 
		    vector< vector< unordered_set<string> > > ans ( n+1 , 
		                                              vector< unordered_set<string> >(m+1) ) ;  
		    
		    memset( dp , 0 , sizeof(dp) ) ;
		    
		    for(int i = 1 ; i<= n ; i++){
		        for(int j = 1 ; j<= m ; j++){
		            dp[i][j] = (s[i-1] == t[j-1]) ? (dp[i-1][j-1] + 1) : max(dp[i-1][j] , dp[i][j-1]) ; 
		        }
		    }
		    
		    for(int i = 0 ; i<= max(n,m) ; i++){
		        if(i<=n) ans[i][0].insert("") ; 
		        if(i<=m) ans[0][i].insert("") ; 
		    }
		    for(int i = 1 ; i<=n ; i++){
		        for(int j = 1 ; j<=m ; j++){
		            if( s[i-1] == t[j-1] ){
		                for(const auto &prev : ans[i-1][j-1]){
		                    ans[i][j].insert( prev + s[i-1] ) ; 
		                }
		            }
		            else if( dp[i-1][j] == dp[i][j-1] ){
		                for(const auto &prev : ans[i-1][j]){
		                    ans[i][j].insert( prev ) ; 
		                }
		                for(const auto &prev : ans[i][j-1]){
		                    ans[i][j].insert( prev ) ; 
		                }
		            }
		            else{
		                const auto &LCS = (dp[i][j-1] > dp[i-1][j]) ? 
		                                   ans[i][j-1] : ans[i-1][j];
		                for(const auto &prev : LCS){
		                    ans[i][j].insert( prev ) ; 
		                }
		            }
		        }
		    }
		    
		    vector<string> all( ans[n][m].begin() , ans[n][m].end() ) ; 
		    sort( all.begin() , all.end() ) ; 
		    return all ; 
		}
