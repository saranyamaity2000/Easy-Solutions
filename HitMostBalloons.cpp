using ll = int ; 
    
    pair<ll,ll> proportion(pair<ll,ll> &p1 , pair<ll,ll> &p2){
        ll x = p1.first - p2.first ;
        ll y = p1.second - p2.second ; 
        ll g = __gcd(x , y) ; 
        x = x/g , y = y/g ; 
        return {x , y} ;
    }
    
    int mostBalloons(int n, pair<int, int> a[]) {
        ll ans = 2 ; 
        for(ll i = 0 ; i<n; i++){
            map<pair<ll,ll> , ll> mp ;
            ll self_hit = 0 ; 
            for(ll j = 0 ; j<n ; j++){
                if(a[i] == a[j]) self_hit++ ;  
                else{
                    auto x = proportion(a[i], a[j]) ;
                    mp[x]++ ; 
                }
            }
            for(auto kv : mp) ans = max(ans , kv.second + self_hit) ;
        }
        return ans ; 
    }

//Problem link -> https://practice.geeksforgeeks.org/problems/4e75764f8f1638eb4f1c5478ca1986043e15e39a/1#
