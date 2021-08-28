int maxCoins(vector<int>&A,int n)
    {
        
	    int dp[n][n] ; 
	    for(int i = 0 ; i<n ; i++){
	        dp[i][i] = A[i] ; 
	    } 
	    for(int gap = 1; gap<n ; gap++){
	        for(int i = 0 ; i<n-gap ; i++){
	            int j = i + gap ; 
	            if(gap == 1){
	                dp[i][j] = max(A[i],A[j]) ; 
	            }
	            else{
	                int choosei = A[i] + min(dp[i+2][j],dp[i+1][j-1]) ; 
	                int choosej = A[j] + min(dp[i][j-2],dp[i+1][j-1]) ; 
	                int max_choice = max(choosei, choosej) ;
	                dp[i][j] = max_choice ; 
	            }
	        }
	    }
	    return dp[0][n-1] ; 
    }
// problem link ( DP )
// https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/?problemStatus=unsolved&problemType=functional&difficulty[]=1&difficulty[]=2&page=1&sortBy=submissions&category[]=Dynamic%20Programming&category[]=Bit%20Magic&category[]=Binary%20Search&query=problemStatusunsolvedproblemTypefunctionaldifficulty[]1difficulty[]2page1sortBysubmissionscategory[]Dynamic%20Programmingcategory[]Bit%20Magiccategory[]Binary%20Search
