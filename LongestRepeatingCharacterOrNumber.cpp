int characterReplacement(string s, int k) {
        using ll = int ; 
        ll ans = -1 ; 
        
        int freq[26] = {0} ;
        
        ll i = 0;
        ll maxcount = 0; 
        
        for(ll j = 0; j<s.size() ; j++){ 
           maxcount = max(maxcount , ++freq[s[j] - 'A']) ; 
           ll len = j - i + 1 ; 
           if(len - maxcount > k){
              if(freq[s[i] - 'A'] == maxcount) maxcount-- ; 
              freq[s[i] - 'A']-- ;
              i++ ;
           }else ans = max(ans , len) ; 
        }
        return ans; 
    }
