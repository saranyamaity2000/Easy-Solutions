int wordLadderLength(string& ss, string& ts, vector<string>& wl) {
    
        
        unordered_set<string> str(wl.begin(), wl.end()) ; 
        
        
        if(str.find(ts) == str.end()) return 0 ; 
        
        if( ss == ts ) return 1 ; 
        
        int n = ss.size() ; 
        
        queue<pair<string,int>>  q ; 
        
        q.push({ss,0}) ; 
        
        while(q.empty() == false)
        {
              string s = q.front().first ;
              int step = q.front().second ; 
              
              q.pop() ; 
              
              if(s == ts) return (step + 1) ; // as phase = step + 1 ;  
              
              for(int i = 0 ; i<n ; i++)
              {
                  
                  char actual = s[i] ; 
                  
                  for(int j = 0 ; j<26 ; j++)
                  {
                      s[i] = 'a' + j  ;
                      
                      if(str.find(s) == str.end()) continue  ; 
                      
                      q.push({s , step + 1}) ; 
                      
                      str.erase(s) ; // as we are taking t into count so no more use of that ! 
                      
                  }
                  
                  s[i] = actual ; 
              }
        }
        
        return 0 ; 
    }

/////// finding all different paths ? 


vector<vector<string>> findSequences(string ss, string ts, vector<string>& l) {
        
        unordered_set<string> str(l.begin(), l.end()) ; 
 
        vector<vector<string>> ans;
        
        
        queue<vector<string>> ways;
        
        
        ways.push( {ss} );
        
        int lvl = 1;
        int minlvl = INT_MAX;
      
        unordered_set<string> visited; 
        
        while (!ways.empty()) {
            
            vector<string> path = ways.front();
            ways.pop();
            
            int curr_lvl = path.size(); 
            
            if (curr_lvl > lvl) { // new level is there ! 
            
                for (string s : visited) str.erase(s);
                visited.clear();
                
                if (path.size() > minlvl)
                    return ans;
                else
                    lvl = path.size();
                    
            }
            
            string last = path.back();
            string news = last ;  // as the last = the new start :) 
            
            for (int i = 0; i < news.size(); ++i) {
                
                char actual = news[i] ; 
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    
                    news[i] = c;
                    
                    if (str.find(news) == str.end()) continue ; 
               
                    vector<string> newpath = path; // copy the path as that path will be used again :p ; 
                    
                    newpath.push_back(news); 
                    
                    visited.insert(news);
                    
                    if (news == ts) {
                        
                        minlvl = lvl ;
                        
                        ans.push_back(newpath);
                    }
                    
                    ways.push(newpath);
                }
                
                news[i] = actual ; 
            }
        }
        return ans ; 
    }
