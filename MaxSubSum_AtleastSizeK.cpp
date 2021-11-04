#define ll long long int
#define inf 1e11 

ll maxSumWithK(ll a[], ll n, ll k) 
{
        ll ms[n] ; 
        
        ms[0] = a[0] ; 
        
        for(ll i = 1 ; i<n ; i++)
        {
            if(ms[i-1] + a[i] > a[i]) ms[i] = a[i] + ms[i-1] ; 
            else ms[i] = a[i] ; 
        }
        
        ll sum = 0 ; 
        ll maxsum = -1LL * inf  ; 
        
        for(ll i = 0 ; i<= n-1 ; i++)
        {
            sum += a[i] ; 
            if(i >= k-1)
            {
               ll maxprev = i-k >= 0 ? ms[i-k] : 0 ; 
               maxsum = max(max(maxprev,0LL) + sum, maxsum) ; 
               sum -= a[i-k+1] ; 
            }
        }
        
        return maxsum ; 
}
