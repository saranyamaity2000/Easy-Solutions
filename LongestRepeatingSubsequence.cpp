unordered_map<string,int> cnt ; 
        unordered_map<string , pair<int,int>> str ; 
        
        for(int i= 0 ; i<n ; i++)
        {
            string now = "" ;
            
            for(int j = i ; j<min(i + n/2, n) ; j++)
            {

                now.push_back(S[j]) ; 
                
                if(str.find(now) == str.end()) {
                    str[now] = {i,j} ; 
                    cnt[now] = 1 ; 
                }
                else
                {
                    if(str[now].second >= i) continue ; 
                    
                    str[now] = {i,j} ; 
                    cnt[now]++ ;
                }
                
            }
        }
        
        string ans = "" ; 
        
        for(auto x : cnt)
        {
            if((ans.size() < x.first.size()) and x.second >= 2) ans = x.first ;
        }
        
        if(ans == "") return "-1" ; 
        else return ans ;
