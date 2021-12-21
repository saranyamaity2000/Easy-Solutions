#include <bits/stdc++.h>
using namespace std;

//-------------------------- USEFUL MACROS --------------------------------------

#define  ff  first
#define  ss  second
#define  pb  push_back
#define  nf  string::npos
#define  ll  long long
#define  ld long double
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  ms(x,y) memset(x,y,sizeof(x))
#define  str to_string
#define  lower lower_bound
#define  upper upper_bound
#define  small_pq_condition ll , vector<ll> , greater<ll>
#define  cline '\n'
#define  inf 1e18
#define  mod 1000000007 //998244353
#define  sz(v) (ll)v.size()
#define  round(x,y)  fixed<<setprecision(y)<<x
#define  setbits(x)      __builtin_popcountll(x)
#define  msb(x) (63 - __builtin_clzll(x)) 
#define  deb(x) if(ON_COMPUTER) cout << #x << " = " << x << "\n"
#define  debc(c) if(ON_COMPUTER) { cout << #c << " = [" ; for(auto i : c) cout<< i <<" "; cout<<"]\n" ; }
#define  getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
// #define  in(arr,n) for(ll i=0; i<n; ++i){ cin>>arr[i]; }
// #define  printv(v) for(auto x : v){ cout << x << " " ;}
#define  bits(n) bitset<n>
#define  all(v) v.begin() , v.end()
#define  rev(v) reverse(all(v))
#define  asn assign
#define  fast_io   ios_base::sync_with_stdio(false) ; cin.tie(NULL)
#define  fo(i,a,b) for(ll i = a ; i < b ; ++i)
#define  buildstring(n,c) string(n,c) // c is char , n is no. of char we want!
#define  rotateright(v , k) std::rotate(v.begin(), v.begin()+v.size()-k, v.end()); // for left put k in neg 
//cnt can be used like cnt(all(a) , v) ; 

template <typename T> istream& operator>>(istream& in, vector<T>& vec) { for (int i = 0; i < vec.size(); i++){ in >> vec[i];}return in;}
template <typename T> ostream& operator<<(ostream& out, const vector<T>& vec) { for (const auto& x : vec) { out << x << " ";} return out;}
template<class P,class D> ostream& operator<<(ostream& os, pair<P,D>p){ os << p.first << " " << p.second ;return os;}
// --------------------------------------------------------------------------------

bool ON_COMPUTER = false ;
const ll N = 5 * (ll)1e6 ;
vll a , b , c ;
ll n , m ;  
string s ;

void hai(){
      cout << "YES" << cline ; 
}
void muri(){
      cout << "NO" << cline ; 
}




void solve()
{
      
}


// IF WRONG -> check constraints , conditions , multiple testcases (t)
// check format is okay ;
// use normally cline , otherwise for flush use endl

signed main()
{
      fast_io;
      ll t = 1 ; 
      cin>>t ; 
      while(t--){
            solve(); 
      } 
      return 0;
}



//<-------------------------------->//<-------------------------------->