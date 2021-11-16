int v ; 

struct comp{
    bool operator()(int a , int b){
         return (abs(v-a)>abs(v-b)) or (abs(v-a) == abs(v-b) and a>b) ; 
    }
};

class Solution{
    public:
    
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        v = x ; 
        priority_queue<int,vector<int>,comp> pq ; 
        for(int i = 0 ; i<n ; i++){
            pq.push(arr[i]) ; 
        }
        vector<int> ans ; 
        for(int i = 0 ; i<k ; i++){
            ans.push_back(pq.top()) ; 
            pq.pop() ; 
        }
        sort(ans.begin(), ans.end()) ; 
        return ans ; 
    } 
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        multiset<int> s(arr.begin(), arr.end()) ;
        vector<int> ans ; 
        for(int i = 0; i<k ; i++){
            auto it = s.lower_bound(x) ; 
            if(it == s.end()){
               --it ; 
               ans.push_back(*it) ;
               s.erase(it) ; 
            }
            else if(it == s.begin()){
               ans.push_back(*it) ;
               s.erase(it) ;
            }
            else{
               auto it2= it ; 
               --it ; 
               if(abs(*it - x) <= abs(*it2 - x)){
                   ans.push_back(*it) ; 
                   s.erase(it) ;
               }else{
                   ans.push_back(*it2) ;
                   s.erase(it2) ; 
               }
            }
        }
        
        sort(ans.begin(),ans.end()) ; 
        return ans ; 
    }  
};

proble link -> https://practice.geeksforgeeks.org/problems/20b8ec4db3f8da0697acdd3d54d9af9f76405443/1#
