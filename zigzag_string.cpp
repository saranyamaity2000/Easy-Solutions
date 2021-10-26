string convert(string s, int n) {
      
          if(n==1) return s ; 
          
          string ans = "" ; 
          
          int start = 0 ; 
     
          for(int gap = 2*(n-1) ; gap >=0 ; gap -= 2)
          {
              int g1 = gap , g2 = 2*(n-1) - gap ; 
              
              int cnt = 0 ; 
              
              int i = start ; 
              
              while(i < s.size())
              {
                 
                  ans.push_back(s[i]) ;
                  
                  if(g1 == 0 or g2 == 0) i += (g1 + g2) ; 
                  
                  else
                  {
                     if(cnt % 2 == 0) i += g1 ; 
                     else i += g2 ; 
                  }
                  
                  cnt++ ; 
              }
              
              start++ ;
          }
          
          return ans ; 
    }


// problem link ->

//https://practice.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows0308/1#
