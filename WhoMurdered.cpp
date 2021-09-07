    /*
    Observation : say given N = 43 output will be 23 
    binary representation of 43 = 101011
    binary representation of 23 = 010111
    
    say N = 5 , output 3 
    binary rep of 5 = 101
    binary rep of 3 = 011
    
    say given N = 35 output 7 
    binary rep of 35 = 100011
    binary rep of 7 =  000111
    
    Pattern : 1> START from left most set bit ( or 31th bit )
              2> keep shifting left most set bit to right untill
                 another set bit found
              3> now consider the new set bit as the left most set bit 
                 and repeat the process above 
    */
    
    int find(int N){
      bool carry = 0 ; 
      for(int i = 31 ; i >= 0 ; i--){
          if(carry == 1){
              if( N & (1<<i) ) // set bit on ith pos 
              {
                  N = N ^ (1<<(i+1)) ; // then set bit on (i+1)th bit 
                  N = N ^ (1<<i) ; // and now turn this off 
              }
          }
          else if(carry == 0){
              if( N & (1<<i) ){
                  N = N ^ (1<<i) ; 
                  carry = 1 ; 
              }
          }
      }
      return (N ^ carry) ;
    }

// DONE BY SARANYA MAITY ( not copied from anywhere ) 



// APPROACH GIVEN in INTERNET one liner - >

 void solve(){
    ll n ;  cin>> n ;
    ll hp = log2(n) ; 
    ll l  = (n ^ ( 1<< hp )) ; // turning off the left most set bit ; 
    ll ans = 2*l + 1 ; 
    cout<<ans ; 
}


