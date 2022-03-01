 long long countStrings(string s)
    {
        using ll = long long ; 
        ll n = s.size() ; 
        ll cnt = 0; 
        ll x[26] = {0} ; 
        
        for(auto &c : s) ++x[c - 'a'] ; 
        
        for(int i = 0 ; i<26 ; i++){
            for(int j = i+1 ; j<26 ; j++){
                cnt += x[i] * x[j] ; 
            }
        }
        
        return cnt + (cnt != n*(n-1)/2) ; 
    }

//https://practice.geeksforgeeks.org/problems/2ac2f925b836b0625d848a0539ffd3d2d2995f92/1#
