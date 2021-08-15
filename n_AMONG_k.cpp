class Solution {
  public:
  
    long long AP(long long start , long long end , long long total){
        return total*(start + end)/2 ; 
    }
    
    vector<long long> distributeCandies(int n, int k) {
       vector<long long> ans(k,0) ; 
       
       // n*(n+1)/2 formula check
       //finding upto which this pattern satisfy 
       long long low = 1 , high = n ; 
       long long count = -1;
       while(low<=high){
           long long mid = low + (high - low)/2 ; 
           if(mid * (mid+1) <= 2*n){
               count = mid ; 
               low = mid + 1 ; 
           }
           else {
               high = mid - 1 ; 
           }
       }
       
       //upto which element its done
       long long upto = count % k ; 
       long long round = count / k + 1;
       // if n = 21 k = 3 
       // its like 1 2 3 
       //          4 5 6 // perfect ending 6/3 + 1 = 3 round
       // but actually 2 whole round there 
       // but its upto is 0 , so compenseted there because 
       // will run for else case only where rounds = round -1 ; 
       
       
       for(int i = 1 ; i<=k ; i++){
           if(i<=upto){
           ans[i-1] = AP(i , (round-1)*k + i , round) ; 
           }
           else{
           ans[i-1] = AP(i , (round-1 - 1)*k + i , round-1) ;
           }
       }
       
       // adding remaining portion to the very next cell !
       n = n - count*(count+1)/2 ; 
       ans[upto] = ans[upto] + n ;
       
       
       return ans ; 
    }
};
