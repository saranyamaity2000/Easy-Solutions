#include<bits/stdc++.h>

using namespace std ;

#define ff first
#define ss second

int main(){
    
    int n ; cin>> n ;
    
    int arr[n] ; 
    for(int i = 0 ; i<n ; i++ ) cin>>arr[i] ; 
    
    unordered_map<int, pair<int,vector<vector<int>> > > dp ; 
    
    
    int maxi = 1 ; 
    
    for(int i = 0 ; i<n ; i++){
        dp[i].ff = 1 ; 
        
        for(int j = 0 ; j<= i-1 ; j++){
            if(arr[j] < arr[i]){
                dp[i].ff = max( dp[i].ff , dp[j].ff + 1) ; 
            }
        }
        
        for(int j = i-1 ; j>=0 ; j--){
            if(arr[j] < arr[i] and (dp[i].ff == (1 + dp[j].ff )) ) {
                for(auto &vec : dp[j].ss){
                    vector<int> temp = vec ; 
                    temp.push_back(arr[i]) ; 
                    dp[i].ss.push_back(temp) ;
                }
            }
        }
        
        if(dp[i].ff == 1){
            dp[i].ss.push_back({arr[i]}) ; 
        }
        
        maxi = max(maxi, dp[i].ff) ; 
    }
    
    cout<<maxi<<endl;
    
    for(int i = 0 ; i<n ; i++){
        if(dp[i].ff == maxi ){
            
            for(auto &vec : dp[i].ss){
                int n = vec.size() ; 
                for(int i = 0 ; i<n ; i++){
                    cout<<vec[i];
                    if(i != n-1) cout<<" -> " ; 
                }
                cout<<endl;
            }
        }
    }
    

  
    return 0 ; 
}
