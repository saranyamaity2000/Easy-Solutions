// DONE BY SARANYA MAITY ( OWN METHOD ) 

// EXPLANATION -> 
/*
   observation : no of odd factors - 1; 
   HOW ? lets say 15
   15 has odd factors 1 , 3 , 5 , 15 ; 
   take 1 . only 15 , just number itself so not okay !

   take 3 , 15/3 = 5 , so 15 can be broken into 5 5 5 
   now this 5 5 5 can be transformed to 5-1 5 5+1 => 4 5 6 

   take 5 , 15/5 = 3 , so 15 can be broken as 3 3 3 3 3 3
   now this can be written as 3-2 3-1 3 3+1 3+2 => 1 2 3 4 5
 
   take 15, now thats a interesting case it is included not because
   it can be broken like others it is included by default 
   as a odd factor as 15 can be written as (15/2) (15/2)+1=> 7 8

   SO NOW YOU GOT THE OBSERVATION BUDDY ? 🔥

   // exceptional cases -> 14 (1 , 7 )
   // 14/7 = 2 , so can be written as 2 2 2 2 2 2 2
                                  2-3 2-2 2-1 2 2+1 2+2 2+3
                                   -1  0   1  2  3   4    5
   // now you MUST BE THINKING -1 is not NATURAL number -_- 
   // you are right !!! 
   //just ignore the section -1 0 1)
   // you will still get 14 by 2 3 4 5 🔥
   
*/

class Solution {
  public:
    int get_odd_factors(int n){
        int cnt = 0 ;
        for(int i = 1 ; i*i<=n ; i++){
            if(n % i != 0 ) continue ;
            if(i % 2 != 0 ) cnt++ ;  
            if((n/i) % 2 != 0) cnt++ ;  
            if( i*i == n ) cnt-- ;  
        }
        return cnt ; 
    }
    int getCount(int N) {
        int oddf = get_odd_factors(N); 
        return oddf - 1 ; // -1 as 1 will not be included as ans.
    }
};
