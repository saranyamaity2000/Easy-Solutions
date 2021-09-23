int dp[100] ; 

int sb[100] ; 


void solve()
{
   
   fill(sb,sb+100,-1) ; 
   fill(dp,dp+100,INT_MAX) ; 

	dp[0] = 0 ;  

	sb[55]=3;
   sb[49]=11;
   sb[54]=13;
   sb[57]=21;
   sb[78]=40;
   sb[87]=53;
   
   sb[27] = INT_MAX;
   sb[36] = INT_MAX;
   sb[46] = INT_MAX;
   sb[74] = INT_MAX;
   sb[93] = INT_MAX;
   sb[96] = INT_MAX;





	  for(int j = 1 ; j<100 ; j++)
	  {
	  	   if(sb[j] == INT_MAX) continue ;

         for(int i = 1 ; i<=6 ; i++)
         {
		  	   if(j-i >= 0 and sb[j-i] != INT_MAX )
		  	      dp[j] = min(dp[j] , dp[j-i] + 1) ;
	  	   }

	  	   if(sb[j] != -1) dp[j] = min(dp[j], dp[sb[j]]) ;
	  }
    
     debc(dp) ; 

}
