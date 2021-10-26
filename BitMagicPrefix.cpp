int count(int N, vector<int> A,int X)
    {
        int prefix=0,ans=N;
        
        for(int i=30;i>=0;i--){
            
            if( X & (1<<i) ){
                prefix^=(1<<i);
                continue;
            }
            
            int ok = 0;
            
            int greater_than_x = prefix ^ (1<<i) ;
            
            for(auto &num:A){
                if( (num & greater_than_x) == greater_than_x )
                     ok++;
            }
            
            ans=min(ans, N-ok);
        }
        
        return ans;
    }
// PROBLEM LINK ->
// https://practice.geeksforgeeks.org/problems/7ba682ec660335b1627f2183f63bd2c8a37391ec/1#
