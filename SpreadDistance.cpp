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
//#define  mod 1000000007 //1e9+7
#define  round(x,y)  fixed<<setprecision(y)<<x
#define  setbits(x)      __builtin_popcountll(x)

#define  deb(x) cout << #x << " = " << x << "\n"
#define  debc(c) cout << #c << "= [" ; for(auto i : c) cout<< i <<" "; cout<<"]\n" 
#define  sortall(v) sort(v.begin(), v.end()) 
#define  getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define  input_vec(vec,n) for(ll i=0; i<n; i++ ){ ll temp; cin>>temp; vec.pb(temp); }
#define  input_arr(arr,n) for(ll i=0; i<n; i++){ cin>>arr[i]; }

#define  fast_io   ios_base::sync_with_stdio(false) ; cin.tie(NULL)

// --------------------------------------------------------------------------------



void solve()
{
   
   int n , m ; 
   cin>> n >> m ; 

   int input[n][m] ; 
   int output[n][m]; 

   int di[]= { 0 ,0  , 1 , -1};
   int dj[]={ 1,-1, 0, 0} ; 

   queue<pair<int,int>> q ;

   for(int i = 0 ; i<n ; i++)
   {
      for(int j = 0 ; j<m ; j++)
      {
        cin>> input[i][j] ; 
        if(input[i][j]){
           output[i][j] = 0 ; 
           q.push({i,j}) ; 
        }
        else 
           output[i][j] = INT_MAX ; 
     }
   }

   while(not q.empty())
   {
      pair<int,int> tp = q.front() ; 
      int i = tp.first ;
      int j = tp.ss ; 
      q.pop() ; 
      for(int k = 0 ; k<4 ; k++)
      {
         if( ((i+di[k]) >= 0) and ((i+di[k]) <n) and ((j+dj[k]) >=0) and ((j+dj[k]) <m) )
         {
            int i_ = i + di[k] , j_ = j+ dj[k] ; 
            if(output[i_][j_] > 1 + output[i][j])
            {
               q.push({i_,j_}) ; 
               output[i_][j_] = 1 + output[i][j] ; 
            }
         }
      }
   }
 
   for(int i =0 ; i<n ; i++)
   {
      for(int j = 0 ; j<m ; j++)
      {
         cout<<output[i][j]<<" " ; 
      }
      cout<<endl;
   }

}


signed main()
{
  fast_io;

  int t = 1 ; 

  while(t--)
  {
     solve();
  }

    return 0;
}



//<-------------------------------->
