#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
 
    int eggDrop(int n, int k) 
    {
        int l = 1 , h = k ;  // l = floor 1 , h = floor k 
        int n_ = n ; // n_ is dummy n ; 

        // to understand below code , you need to have 

        // understanding of binary search ! 

        // lets say there are 10 floors 

        // how much maximum time it can take ???? 

        // 10 floor , use binary search -->

        // then middle = ( 1 + 10 )/ 2 = 5 ; // say 5 is not the ans .

        // then now its important will you search in ( 1 to 4 ) or ( 6 to 10 ) ?
        //                                            LEFT HALF     RIGHT HALF

        // we will go for ( 6 - 10 ) , why not ( 1 to 4 )?

        // because ( 1 to 4 ) we have ( 4 - 1 + 1) = 4 floors 

        // but ( 6 to 10 ) we have ( 10 - 6 + 1 ) = 5 floors 

        // as 5 floor > 4 floor ( worst case we have to consider so we will choose RIGHT HALF) 

        // and as ( l + h ) / 2 will always step down the value ( like (3+4)/2 = 3 ( less than3.5))

        // So always considering RIGHT HALF will give me worst case scenario .

        while(l<=h){

            if( n_ == 1 ) break ; 
            // if there is 1 egg you can not take risk to break it !!!
            // and check it if this is the 'f' floor or not !

            int mid = (l+h)/2 ; 
            l = mid+1 ; // as we discussed always taking RIGHT CONSIDERATION !
            // so that next time we check for range ( mid + 1 ) to h ;

            n_ -- ; // now we have 1 less egg as we have used it to decide which
            // half we should check ( its for reality but here we only checking RIGHT half
            // as WORST CASE has to considered ! 
        } 
        
        int used_eggs_to_determine_direction = (n - n_) ; 

        int floor_left_to_be_checked = ( h - l + 1) ; 

        
        return  ( used_eggs_to_determine_direction + floor_left_to_be_checked ) ; 
    }
};


int main()
{   
  int n = 12 , k = 100; // sample values 
  Solution ob;
  cout<<ob.eggDrop(n, k)<<endl;
  return 0;
}
  