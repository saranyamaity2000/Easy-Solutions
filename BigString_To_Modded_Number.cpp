ll value(string &str , int mod){
       ll mod_val = 0 ; 
       for(ll i= 0 ; i<str.size() ; i++){
           mod_val = ((mod_val * 10) + str[i]) % mod ;
       }
       return mod_val ; 
}