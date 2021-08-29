class Solution{
   public:
    void put_relation_in_graph(string &prev , string &present , vector<int> Graph[]){
            int n = min(prev.size() , present.size()) ;
            
            int _i = 0 ; 
            
            while(_i < n and prev[_i] == present[_i]){
                _i++ ; 
            }
            
            if(_i != n) Graph[prev[_i] - 'a'].push_back(present[_i] - 'a') ; 
    }
    
    string findOrder(string dict[], int N, int K) {
        
        vector<int> Graph[K] ; 
        string prev = dict[0] ; 
     
        for(int i = 1 ; i<N ; i++){
            string present = dict[i] ; 
            put_relation_in_graph(prev,present,Graph) ; 
            prev = present ; 
        }
        
        //TOPO_SORT_START(Queue Method)
        
        int in[K] ; memset(in,0,sizeof(in)) ; 
        
        for(int i = 0 ; i< K ; i++){
             for(auto v : Graph[i]){
                 in[v]++ ; 
             }
        }
        
        queue<int> Q ; 
        string res = "" ; 

        
        for(int i = 0 ; i<K ; i++){
            if(in[i] == 0) Q.push(i) ; 
        }
        
        while(not Q.empty()){
            int tp = Q.front() ; 
            Q.pop() ; 
            res.push_back(tp + 'a') ; 
            for(auto v : Graph[tp]){
                in[v]--; 
                if(in[v] == 0) Q.push(v) ; 
            }
        }
        
        //sending value  ; 

        return res ; 
    }
    
};

// CONCEPT USED - TOPOLOGICAL SORT ! 
