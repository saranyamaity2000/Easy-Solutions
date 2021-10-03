#include <bits/stdc++.h>
using namespace std;

//-------------------------- USEFUL MACROS --------------------------------------

#define  ff  first
#define  ss  second
#define  pb  push_back
#define  nf  string::npos
#define  ll  long long
#define  str to_string

#define  inf 1e18
#define  mod 1000000007 //1e9+7
#define  round(x,y)  fixed<<setprecision(y)<<x
#define  setbits(x)      __builtin_popcountll(x)

#define  deb(x) cout << #x << " = " << x << "\n"
#define  debc(c) cout << #c << "= [" ; for(auto i : c) cout<< i <<" "; cout<<"]\n" 
#define  sortall(v) sort(v.begin(), v.end()) 
#define  getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define  input_vec(vec,n) for(int i=0; i<n; i++ ){ int temp; cin>>temp; vec.pb(temp); }
#define  input_arr(arr,n) for(int i=0; i<n; i++){ cin>>arr[i]; }

#define  fast_io   ios_base::sync_with_stdio(false) ; cin.tie(NULL)

// --------------------------------------------------------------------------------

int n , m , k ; 


void solve()
{

  cin >> n >> m ;

  vector<int> depend[m] ; 

  for(int i = 0 ; i<m ; i++)
  {
      cin >> k ; 
      while(k--)
      {
         int t ; cin >> t ; t-- ; 
         depend[i].pb(t) ; 
      }
  }
  
  int p[m] ; 

  input_arr(p , m) ; 

  int total = 0 ; 

  for(int states = 0 ; states<(1<<n) ; states++)
  {
      bool canbe = true ;

      for(int i = 0 ; i<m ; i++)
      {
         int cnt = 0 ; 

         for(auto s : depend[i])
         {
            if(states & (1 << s)) cnt++ ; 
         }

         if(cnt % 2 != p[i])
         {
            canbe = false ; 
            break ; 
         }
      }

      if(canbe) total++ ; 
  }

  cout << total ; 


}



signed main()
{
   fast_io;

   int t = 1 ; 

   //cin>>t ; 

   while(t--)
   {
      solve();
   }
   
   return 0;
}



//<-------------------------------->

PROBLEM LINK -> https://atcoder.jp/contests/abc128/tasks/abc128_c
