 int candies(int m, int n) 
    { 
      
       int x = n*m - m - n ; 
       // x = max num that cant be visited ; 
       unordered_set<int> s ; 
       
       queue<int> q ; 
       q.push(x) ; 
       
       int cnt = 0 ; 
       
       while(not q.empty())
       {
          int tp = q.front() ; 
          q.pop() ;
          cnt++ ; 
          int a = tp - n , b = tp - m ; 
          if( a > 0 and s.find(a) == s.end()) 
          {
              s.insert(a) ; 
              q.push(a) ; 
          }
          if( b > 0 and s.find(b) == s.end())
          {
              s.insert(b) ; 
              q.push(b) ; 
          }
       }
       
       return cnt ;
      
    } 

// beautiful solution !
