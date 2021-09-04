#define sortall(v) sort(v.begin() , v.end())

class Solution {
  public:
    int numOfSubsets(int arr[], int n, int k) {
        
        vector<int> arr1(arr, arr + n/2) ; 
        vector<int> arr2(arr + n/2, arr+n) ;
        vector<int> s1 , s2 ; 
        
        int n1 = n/2 , n2 = n - n1 ; 
        for(int i = 0 ; i< (1<<n1) ; i++ ){
            int mul = 1 ; 
            for(int j = 0 ; j<n1 ; j++){
                if(i & (1<<j)) mul *= arr1[j] ;
                if(mul > k) break ; 
            }
            if(mul <= k) s1.push_back(mul) ; 
        }
        for(int i = 0 ; i< (1<<n2) ; i++ ){
            int mul = 1 ; 
            for(int j = 0 ; j<n2 ; j++){
                if(i & (1<<j)) mul *= arr2[j] ;
                if(mul > k) break ; 
            }
            if(mul <= k) s2.push_back(mul) ; 
        }
        
        sortall(s1) ; sortall(s2) ; 
        
        int total = 0 ; 
        for(int i=0 ; i<s1.size() ; i++){
            int cnt = upper_bound(s2.begin(), s2.end(), k/s1[i]) - s2.begin();
            total += cnt ; 
        }
        
        return total-1 ; // (as 0 * 0 case not to be considered) 
    }
};

// Meet in the middle concept 
// better when K >> N like N = 30 K = 1e6
