public:
        int* get_lps(string &str){
             int n = str.size() ; 
             int* lps = new int[n]; 
             lps[0] = 0 ; 
             int len = 0 ; 
             int i = 1 ; 
             
             while(i<n){
                 if(str[len] == str[i]){
                     len++ ; 
                     lps[i] = len ; 
                     i++ ; 
                 }
                 else{
                     if(len == 0) { lps[i] = 0 ; i++ ; }
                     else len = lps[len-1] ; 
                 }
                
             }
             
             return lps ; 
        }
        
        vector<int> search(string pat, string txt)
        {
            int n = txt.length() ; 
            int m = pat.length() ; 
            int* lps = get_lps(pat) ;
            
            vector<int> res ; 
            
            int i = 0, j = 0 ; 
            
            while(i<n){
                
                 if( txt[i] == pat[j] ) { 
                     i++ ; 
                     j++ ; 
                     if( j == m ) {
                         res.push_back(i- m + 1) ; 
                         j = lps[j-1] ; 
                     }
                 } 
                 else{
                     if( j == 0 ) i++ ; 
                     else j = lps[j-1] ; 
                 }
            }
            
            delete[] lps ; 
            
            if( res.size() == 0 ) res.push_back(-1) ; 
            
            return res ; 
        }

// NOT DONE BY ME , I LIKE THIS PROBLEM VERY MUCH ! 
