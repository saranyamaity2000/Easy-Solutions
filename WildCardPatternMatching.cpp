/*

example - > aabbcc
            ?ab*c

*/

#include<bits/stdc++.h>
using namespace std ; 


bool wildcard(string& s1 , string& s2)
{
    
     int n1 = s1.size() ; 
     int n2 = s2.size() ; 
     
     bool dp[n1+1][n2+1] ; 
     
     memset(dp,0,sizeof(dp)) ; 
     
     dp[0][0] = 1 ; 
     dp[0][1] = (s2[0] == '*') ; 
     
     for(int i = 1 ; i<=n1 ; i++){
         for(int j = 1 ; j<=n2 ; j++ ){
             if( s1[i-1] == s2[j-1] or s2[j-1] =='?' ) dp[i][j] = dp[i-1][j-1] ; 
             else if(s2[j-1] == '*') dp[i][j] = dp[i-1][j] | dp[i-1][j-1] | dp[i][j-1] ; 
             else dp[i][j] = 0; 
         }
     }
     
     return dp[n1][n2] ; 
     
}

int main(){
    
    string s1 , s2 ; 
    cin>> s1 >> s2 ; 
    
    string s3 = "" ; 
    
    for(int i = 0 ; i<s2.size() ; i++){
        if( i!=0 and (s2[i-1] == '*') and (s2[i] == s2[i-1]))
            continue ; 
        s3.push_back(s2[i]) ; 
    }
    
    bool res = wildcard(s1,s3) ; 
    
    if(res) cout<<"true" ; 
    else cout<<"false" ; 
    
    return 0 ;
}
