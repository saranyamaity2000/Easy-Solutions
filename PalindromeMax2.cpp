
// THIS APPROACH is not mine , I liked this so I am posting this !!

/*
Q. Given two integers N and K, the task is to find the count 
of palindromic strings of length lesser than or equal to N, with
first K characters of lowercase English language, such that each
character in a string doesn’t appear more than twice.

Note: Anwer can be very large, so, output answer modulo 1e9+7
*/
   
ll helper(ll N, ll K){
	    if(N == 1)
        return K;
        
        ll count = 1;
        for(ll i=0; i<N/2; i++){
            count = (count*(K-i))%MOD;
        }
        
        if(N&1){ // if n odd 
            if((K-N/2) >= 1){
                count = (count*(K-N/2)%MOD);
            }else{
                return 0;
            }
        }
        return count%MOD;
   }
	
   int palindromicStrings(ll N, ll K){
        int count = 0;
        for(ll i=1; i<=N; i++){
            if(N > 2*K) break;
            
            int cur = helper(i, K);
            count = (count + cur) % MOD;
        }
        return count;
   }
