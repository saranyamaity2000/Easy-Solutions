#include <bits/stdc++.h>
using namespace std;

//-------------------------- USEFUL MACROS --------------------------------------
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  eb  emplace_back
#define  pf  push_front
#define  nf  string::npos
#define  ll  long long
#define  mp  make_pair
#define  mt  make_tuple
#define  vi  vector<ll>
#define  pi  pair<ll,ll>
#define  str to_string

#define  umap unordered_map
#define  uset unordered_set
#define  endl "\n"
#define  inf 1e18
#define  mod 1000000007 //1e9+7
#define  DA(type,arr,n) type* arr = new type[n]
#define  round(x,y)  fixed<<setprecision(y)<<x
#define  setbits(x)      __builtin_popcountll(x)

#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define  at(tup,i) get<i>(tup) // for tuple value check 
#define  loop(i,a,b) for(ll i = a;i<=b;i++)
#define  input_vec(vec,n) for(ll i=0;i<n;i++ ){ ll temp; cin>>temp; vec.pb(temp); }
#define  input_arr(arr,n) for(ll i = 0; i<=n-1 ; i++){ cin>>arr[i]; }
#define  mset multiset   // have to use mset<type, greater<type>> for rev order store
#define fast_io   ios_base::sync_with_stdio(false) ; cin.tie(NULL)

//<-----------------  CODE STARTS FROM HERE BY < SARANYA MAITY > ------------------->








// <----------- SOLVE ----------->

void solve(){
  int n ; 
  cin>> n; 
  ll arr[n] ; 
  input_arr(arr, n) ; 
  ll dp[n][n] ;
  for(int gap = 0 ; gap<n ; gap++){
    for(int i = 0 ; i<n-gap ; i++){
        int j = i + gap ;
        if(gap == 0) dp[i][j] = 0 ;
        if(gap == 1) dp[i][j] = max(arr[i],arr[j]) ; 
        else if(gap >= 2)
        dp[i][j] = max( arr[i] + min(dp[i+2][j] , dp[i+1][j-1]) , 
                        arr[j] + min(dp[i+1][j-1] , dp[i][j-2]) ) ; 
    }
  }
  cout<<dp[0][n-1] ; 
}


// <----- INT MAIN --------------> 

int main(){
    fast_io;
    int t = 1 ; 
    //cin>>t ; 
    while(t--){
        solve();
    }
    return 0;
}




//<---------------------- END --------------------->
