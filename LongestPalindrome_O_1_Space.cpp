class Solution {
public:
    pair<int,int> max(pair<int,int> a , pair<int,int> b){
        return (a.second - a.first) > (b.second - b.first) ? 
                a : b ; 
    }
    
    pair<int,int> expand(int l , int r, const string &s){
        while( l>= 0 and r<s.size() and (s[l] == s[r]) ){
            l-- ; 
            r++ ;
        }
        if( l+1 > r-1 ) return {r,r} ;
        return {l+1,r-1} ; 
    }
    
    string longestPalindrome(string s) {
           
        int n = s.size() ; 
        
        if(n < 1) return "" ;
        
        int start = 0 , end = 0 ; 
        
        for(int i = 0 ; i<n; i++){
            // take current element as the center 
            pair<int,int> len1 = expand(i,i,s) ; 
            // take gap after this element as center 
            pair<int,int> len2 = expand(i,i+1,s) ;
            
            pair<int,int> len = max(len1, len2) ; 
            
            if( end - start < len.second - len.first ){
                start = len.first ;
                end = len.second ; 
            }
        }
        
        return s.substr( start , end - start + 1) ;
    }
};

// Interesting process 
