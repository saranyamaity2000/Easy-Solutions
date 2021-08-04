#include <bits/stdc++.h>
using namespace std;

//-------------------------- USEFUL MACROS --------------------------------------
#define  ff first
#define  ss second
#define  pb    emplace_back
#define  pf    push_front
#define  not_found    string::npos
#define  ll    long long
#define  lli   long long int
#define  mp    make_pair
#define  mt    make_tuple
#define  v(t) vector<t>
#define  p(t1,t2) pair<t1,t2>

#define  umap unordered_map
#define  uset unordered_set
#define  endl "\n"
#define  inf 1e18
#define MOD 1000000007 //1e9+7
#define DA(type,arr,n) type* arr = new type[n];
#define round(x,y)  fixed<<setprecision(y)<<x
#define setbits(x)      __builtin_popcountll(x)


#define  at(tup,i) get<i>(tup) // for tuple value check 
#define  loop(i,a,b) for(ll i = a;i<=b;i++)
#define  revloop(i,a,b) for(ll i = b;i>=a;i--)
#define  print_container(box) for(auto i : box){ cout<<i<<" "; }
#define  input_vec(vec,n) for(int i=0;i<n;i++ ){ ll temp; cin>>temp; vec.pb(temp); }
#define  input_arr(arr,n) for(ll i = 0; i<=n-1 ; i++){ cin>>arr[i]; }
#define  print_arr(arr,n) for(ll i = 0; i<=n-1 ; i++){ cout<<arr[i]<<" "; }
#define  mset multiset   // have to use mset<type, greater<type>> for rev order store
#define fast_io   ios_base::sync_with_stdio(false) ; cin.tie(NULL)
//#define mx 20005
//<-----------------  CODE STARTS FROM HERE BY < SARANYA MAITY > ------------------->





// <--------USE FULL FUNCTIONS HERE ----------->








// <----------- IMPORTANT PART ----------->

const int mx = (int)2e4 + 5 ;
bitset<mx> dp , mask ; 
void solve();


int main(){
    fast_io;
    mask.set() ;  
    int t = 1 ; 
    cin>>t ; 
    while(t--){
        solve();
    }
    return 0;
}

bitset<mx> masking(int l, int r) {
    // here l denotes array left , 
    // bitset works like normal bits so start from right 
    // so we have to set everything to 0 , from 0 to l-1 pos 
    // total ( l-1 - 0 + 1) = l right shift left shift  
    // as start from 0 ;
    // for that (mask>>l)<<l ;
    // now R values stored at R+1 position 
    // so remaining right side ( left side according to bitset )
    // is ( mx - (R+1))
    // OR you can say we have to make 0 from r+2 to mx 
    // i.e ( mx - (R+2) + 1) = ( mx - (R+1) ) 
    return  (((mask >> l) << l) << (mx - (r+1)) ) >> (mx - (r+1)) ;

}

void solve(){
    dp.reset() ;
    dp.set(0) ; 
    int n , height; 
    cin>> n>> height; 

    DA(int , arr , n) ;

    loop(i , 0 , n-1) {
        cin>>arr[i] ; 
        arr[i] = min(arr[i] , height) ; 
    }

    sort( arr , arr + n , greater<int>()) ; 
    int curr = 0 ; 
    for(int i = 0 ; i<n ; i++){
        curr += arr[i] ; 
        dp = dp | (dp << arr[i]) ; 
        int l = height ; 
        int r = curr - height; 
        bool chance_for_b = ( l <= r ) ; 
        if( chance_for_b and ( masking( l,r ) & dp ).count() ) {
             // second part checking if l to r anyone is present , 
             // because then lets say x = ( r - l ) ; 
             // so (l , l+1 , l+2 , ... l+x ) if anyone if these bits
            // are present then we are done !!! 
             cout<<i+1<<endl ;  
             delete[] arr; 
             return; 
        }
    }
    cout<<-1<<endl ; 
    delete[] arr ; 
}




//<---------------------- END --------------------->

// MY OWN explnation ! .
