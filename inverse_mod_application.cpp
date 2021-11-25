	public:
    long long int mod = 1000000007;
	long long int powerMod(long long int base,long long int pow)
	{
	    long long int  ans=1;
	    while(pow>0){
	        if(pow%2!=0)
	            ans=(ans*base)%mod;
	        pow/=2;
	        base=(base*base)%mod;
	    }
	    return ans;
	}
	long long int  inverse_mod(long long int  a,long long int b)
	{
	    return (a*powerMod(b,mod-2))%mod;
	}
    int totalWays(int n, int k) {
    	n--,k--;
    	if(k > n)
    		return 0;
    	long long int fact[n+1];
    	
    	fact[0] = 1;
    	fact[1] = 1;
    	for(long long int  i = 2; i <= n; i++){
    		fact[i] = ((fact[i-1] % mod) * (i % mod))%mod;
    	}
    	
    	long long int ans = 1;
    	ans = fact[n];
    	long long int r = (fact[k] % mod * fact[n-k] % mod)%mod;
    	ans = inverse_mod(ans, r);
    	return int(ans);
    }
};

link -> https://practice.geeksforgeeks.org/problems/money-distributions5924/1#
