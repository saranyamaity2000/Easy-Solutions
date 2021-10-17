#define pb push_back

class Solution {

  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        
        vector<int> inc ; 
        
        for(int i = 0 ; i<n ; i++)
        {
            bool present = binary_search(b , b+m , a[i]) ; 
            
            if(not present) continue ; 
      
            int pos = lower_bound(inc.begin() , inc.end(), a[i]) - inc.begin() ;
            
            if(pos == inc.size()) 
            {
                inc.pb(a[i]) ; 
            }
            else
            {
                inc[pos] = a[i] ;
            }
        }
        
        int tm = inc.size() ; 
        
        return  (n - tm) + (m - tm) ; 
        
    }
};
