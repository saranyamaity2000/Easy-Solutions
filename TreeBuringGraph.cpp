/*
// problem statement : ->
Given a binary tree and a node called target. Find the minimum
 time required to burn the complete binary tree
 if the target is set on fire.
 It is known that in 1 second all nodes connected to
 a given node get burned. 

// TWIST ADDED -> THERE ARE NO UNIQUE DATA  ( the way i solved )
SO IF TARGET is 8 , all nodes having data 8 will be starting point

*/





#define ff first 
#define ss second

const int N = 1e4 + 5 ; 

vector<vector<int>> g ;

//bool vis[N] ;

int min_time[N] ; 

unordered_map<Node*, int> mp ; 

vector<int> start ; 

int src = 0 ; 

class Solution {
  public:
    int mini = 0 ; 
    
    void init()
    {
        src = 0 ; 
        mp.clear(); 
        start.clear() ;
        mini = 0 ; 
        g = vector<vector<int>>(N) ;
    }
  
    void assign(Node* root,int target)
    {
        if(root == NULL){
          mp[root] = -1 ;  
          return ;
        }
        
        min_time[src] = INT_MAX ; 
        //vis[src] = false ; 
        if(root->data == target)
        {
           start.push_back(src) ; 
           min_time[src] = 0 ;
        }
        
        mp[root] = src++ ;
        
        assign(root->left,target) ; 
        assign(root->right,target) ; 
    }
    
    void make_graph(Node* root)
    {
        
        int u = mp[root] ; 
        if( u == -1 ) return ;
        
        int v1 = mp[root->left] ; 
        int v2 = mp[root->right] ; 
        if(v1 != -1) 
        {
            //cout << "ok1" ; 
            g[u].push_back(v1) ; 
            g[v1].push_back(u) ; 
        }
        if(v2 != -1) 
        {
            //cout << "ok2" ; 
            g[u].push_back(v2) ; 
            g[v2].push_back(u) ; 
        }
        
        make_graph(root->left) ; 
        make_graph(root->right) ; 
        
    }
    
    int minTime(Node* root, int target) 
    {
        init();
        assign(root, target) ;
        make_graph(root);
   
        
        queue<pair<int,int>> q ; 
        
        for(int i : start)
        {
            q.push({i,0}) ;    
        }
    
        
        while(q.empty() == false)
        {
            int u = q.front().ff ; 
            int val = q.front().ss ; 
            
            q.pop() ; 
            
            mini = max( mini , val ) ; 
             
            for(int v : g[u])
            {
                if(val + 1 < min_time[v])
                {
                    min_time[v] = val + 1 ; 
                    q.push({v, val+1}) ; 
                }
            }
        }
        
        return mini ; 
    }

// COMPLETE MY PROCESS :) 


