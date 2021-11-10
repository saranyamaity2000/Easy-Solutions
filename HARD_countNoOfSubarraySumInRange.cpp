ll util(vector<int> a , ll x){
       ll ans = 0 ;
       /* no of subarrays that sum < x 
          [ 2 3 4 -3 5 -2 4]
          x = 7
          start = 0 , end = 0 , sum = 2
          start = 0 , end = 1 , sum = 5
          start = 0 , end = 2 , sum = 9 ( not less than x )
          increase start and so on 
       */
       ll n = a.size() ; 
       ll sum = 0 ;
       ll start = 0 , end = 0; 
       
       while(end < n){
          sum += a[end] ;
          while(start<=end and sum >= x){
              sum -= a[start] ; 
              start++ ;
          }
          ans += (end - start + 1) ;
          end++ ;
       }

       return ans ; 
    }
    ll countSubarray(int n,vector<int> a,ll l,ll r) {
       ll left = util(a, l) ; 
       ll right = util(a, r+1) ; 
       return (right - left) ; 
    }

pronlem link -> https://practice.geeksforgeeks.org/problems/count-the-number-of-subarrays/1#
