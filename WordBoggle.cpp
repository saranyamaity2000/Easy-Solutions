class Solution {
    int row[8]  = { 0 , 0 , 1 , 1 , 1 , -1 , - 1, -1}; 
    int col[8] = { 1 , -1 , 1 , -1, 0 , 1 , -1 , 0 } ; 
public:
    struct trienode{
      unordered_map<char , trienode*> MP ; 
      int cnt ; 
      trienode(){
          MP.clear() ; 
          cnt = 0 ; 
      }
    } ;
    
    void insert_trie(trienode* dict , string &s){
        trienode* temp = dict; 
        for(int i = 0 ; i<s.size() ; i++){
            if(temp->MP.find(s[i]) == temp->MP.end()){
                temp->MP[s[i]] = new trienode() ;
            }
            temp = temp->MP[s[i]] ; 
        }
        temp->cnt += 1; 
    }
    
    bool safe(int r , int c , int m , int n){
        if( r>=0 and r<m and c>=0 and c<n) return 1 ; 
        return 0;
    }
    
    void dfs(vector<vector<char>> &board , trienode* dict , int r , int c ,int m , int n,  vector<string> &res , string &str){
        
        if(dict->cnt)
        {
            while(dict->cnt){ 
            res.push_back(str) ;
            dict->cnt -=1 ;
            }
        }
        
        for(int i = 0 ; i<8 ; i++){
            
            int r_ = r + row[i] ;
            int c_ = c + col[i] ; 
            
            if(safe( r_ , c_ , m , n) and (board[r_][c_] != '+') ){
                char prev = board[r_][c_]; 
                if(dict->MP.find(prev) != dict->MP.end()){
                    board[r_][c_] = '+' ;
                    str.push_back(prev) ; 
                    dfs( board , (dict->MP)[prev] , r_ , c_ , m , n , res , str) ; 
                    str.pop_back() ; 
                    board[r_][c_] = prev ; 
                }
            }
    
        }
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string> &diction) {

	   trienode* dict = new trienode() ; 
	   for(auto i : diction){
	        insert_trie( dict , i) ; 
	    }
 
	    int m = board.size() ; int n = board[0].size() ;

	    vector<string> ans ;
	    string str = "" ; 
	    
	    for(int i = 0 ; i<m ; i++){
	        for(int j = 0; j<n ; j++){
	            char prev = board[i][j] ;
	           
	            if(dict->MP.find(prev) != dict->MP.end()){
                    board[i][j] = '+' ;
                    str.push_back(prev) ; 
                    dfs( board , dict->MP[prev] , i , j ,m ,n, ans , str) ; 
                    str.pop_back() ; 
                    board[i][j] = prev ; 
                }
	        }
	    }
	    return ans ; 
	}


// DONE BY SARANYA MAITY 
// ITS MY OWN PROCESS , 
// My trie solution is different than what is present in GFG
