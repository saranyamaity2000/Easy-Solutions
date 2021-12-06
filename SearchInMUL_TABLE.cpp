"""
Hint / Logic :

Assume X is our ans.

So, check if X is our ans

IF (occurrence of elements ≤ X) < k :

      then, X cant our possible ans

      now check recursively for numbers > X

ELSE:

      X can be our possible ans ,

      keep it as ans ,

      now check recursively for numbers < X


IMPLEMENT THIS LOGIC WITH BINARY SEARCH ( recursive / iterative ) """

//CODE -> 

Solution {
public:
    using ll = int ; 
    ll less_than_equal(ll num,ll  m,ll n) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(num / i, n);
        }
        return cnt ; 
    }

    ll KthSmallest(ll m,ll  n, ll k) {
        ll l = 0 , h = m*n ;
        ll ans = -1 ; 
        while(l<=h){
            ll mid = l + (h - l)/2 ; 
            ll occur = less_than_equal(mid , m , n) ; 
            if(occur >= k){
               ans = mid ; 
               h = mid - 1 ; 
            }else{
               l = mid + 1 ; 
            }
        }
    }
}


