#include<bits/stdc++.h>

using namespace std ; 


bool reg(string &str, string &pat){
    
    int n1 = str.size() , n2 = pat.size() ; 
    
    bool rep[n2] ; 
    memset(rep,0,sizeof(rep)) ; 
    
    for(int i = 0 ; i<n2-1 ; i++){
        rep[i] = (pat[i+1] == '*') ; 
    }
    
    bool dp[n1+1][n2+1] ; 
    memset(dp, 0 , sizeof(dp)) ; 
    
    dp[0][0] = 1 ; 
    for(int i = 1 ; i<=n2 ; i++){
        if(pat[i-1] == '*' or rep[i-1] ) dp[0][i] = dp[0][i-1] ; 
    }
    
    for(int i = 1 ; i<=n1 ; i++){
        for(int j = 1 ; j<=n2 ; j++){
            
               if(pat[j-1] == '*')  dp[i][j] = dp[i][j-1] ; 
               
               else if( (str[i-1] == pat[j-1]) or (pat[j-1] == '.') ){
                 dp[i][j] |= dp[i-1][j-1] ;
                 if(rep[j-1])
                 dp[i][j] |= (dp[i-1][j] | dp[i][j-1])  ; 
               }
               
               else if(rep[j-1]){
                   dp[i][j] |= dp[i][j-1] ; 
               }
        }
    }
    
    return dp[n1][n2] ; 
}

int main(){
    
    string s1 , s2 ; 
    cin>> s1 >> s2 ; 
    
    bool ans = reg(s1,s2) ;
    
    if(ans) cout<<"true" ; 
    else cout<<"false" ;
    
    
    return 0 ; 
}
