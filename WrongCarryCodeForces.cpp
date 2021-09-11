void solve(){
 
    string s ; 
 
    cin>> s;  
 
    int n = s.size() ; 
 
    int even = 0 , odd = 0 ; 
    
    for(int i = 0 ; i <= n-1 ; i++ ){
 
        if(i%2) odd = 10 * odd + (s[i]-'0') ; 
 
        else even = 10 * even + (s[i]-'0') ; 
 
    }
 
    cout << ( odd + 1 ) * ( even + 1 ) - 2 << endl ; 
 
}

// Link Problem -> https://codeforces.com/contest/1567/problem/C
