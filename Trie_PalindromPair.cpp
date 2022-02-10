bool palin(string s){
    int n = s.size() ; 
    for(int i = 0 ; i<n/2 ; i++){
        if(s[i] != s[n - 1 - i]) return false ; 
    }
    return true ; 
}

class Trie {
    private:
        bool isend = 0 ; 
        Trie* children[26] ; 
        int isrev = 0; 
        int isnormal= 0; 
    public:
        Trie() : isend(false) {
            for(int i = 0 ; i<26 ; i++) children[i] = NULL ; 
        }
        void insert(string s , int rev = 0){
            Trie* temp = this ; 
            for(int i = 0 ; i<s.size() ; i++){
                if(temp->children[s[i] - 'a'] == NULL) temp->children[s[i] - 'a'] = new Trie() ; 
                temp = temp->children[s[i] - 'a'] ; 
            }
            temp->isend = 1 ; 
            temp->isrev += (0 ^ rev ) ; 
            temp->isnormal += (1 ^ rev) ;
        }
        bool search(string s){
            Trie* temp = this ; 
            for(int i = 0 ; i<s.size() ; i++){
                if(temp->children[s[i] - 'a'] == NULL) temp->children[s[i] - 'a'] = new Trie() ; 
                temp = temp->children[s[i] - 'a'] ; 
            }
            if(palin(s)) return temp->isnormal >= 2 ; 
            return temp->isnormal >= 1 ; 
        }
        bool modsearch(string s , int rev = 0 ){
            Trie* temp = this ; 
            bool pal[s.size()] = {0} ; 
            for(int i = 0 ; i<s.size() ; i++){
                 if(palin(s.substr(i))) pal[i] = true ; 
            }
            for(int i = 0 ; i<s.size() ; i++){
                temp = temp->children[s[i] - 'a'] ; 
                if(i<s.size()-1 and temp->isend and pal[i+1]) return true ; 
            }
            return false ; 
        }
} ; 


class Solution{   
  public:
    
    bool palindromepair(int n ,  string a[]) {
        
          Trie trie; 
          
          for(int i = 0 ; i<n ; i++){
              string s = a[i] ; 
              trie.insert(s) ; 
              reverse(s.begin() , s.end()) ;
              trie.insert(s , 1) ; 
          }
    
          bool done = 0 ; 
          for(int i = 0 ; i<n ; i++){
              string s = a[i] ; 
              done |= trie.modsearch(s) ;
              reverse(s.begin() , s.end()) ; 
              done |=  trie.modsearch(s , 1) ;
              done |= trie.search(s) ; 
          }
          return done ; 
    }

};
