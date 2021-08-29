#define MOD 1000000007 //1e9+7
 
 const int siz = 1e6 + 5 ; 

 bool seive[siz] ; 

 void fill_sieve(){
      memset(seive, true, sizeof(seive)) ;
      seive[0] = seive[1] = false ; 
      for(int i = 2 ; i*i<=siz ; i++){
            if(seive[i]){
                for(int j = i*i ; j<=siz ; j += i){
                    seive[j] = false ; 
                }
            }
      }
 }

 bool prime(string s){
    int n = stoi(s) ;
    return seive[n] ; 
 }
// <----------- IMPORTANT PART ----------->

void solve();

int main(){
    fast_io;
    int t = 1 ; 
    cin>>t ; 
    while(t--){
        solve();
    }
    return 0;
}

void solve(){
   string s ; 
   cin>> s; 
   int n = s.size() ;
   fill_sieve() ;
   int dp[n+1] ; 
   memset(dp, 0 , sizeof(dp)) ;  
   dp[0] = 1; 
   for(int i = 1 ; i<=n ; i++){
       for(int j = 1 ; j <= min(i,6) ; j++){
           if(s[i-j] != '0' and prime(s.substr(i-j,j)) ){
                dp[i] = (dp[i] + dp[i-j])%MOD ; 
           }
       }
   }
   cout<<dp[n]<<endl ; 
}

// BOTTOM UP APPROACH DONE BY ME ! 
