	string canbe(long long a, long long n, long long m){
	    long long ans = 1 ; 
	    while(n--){
	       ans *= a ;
	       if(ans > m){
	           return "dec" ; 
	       }
	    }
	    if(ans == m) return "done" ; 
	    else return "inc" ; 
	}
	int NthRoot(int n, int m)
	{
	   long long l = 1 , r = 1000000007 ; 
	   
	   while(l<=r){
	       long long mid = l + (r-l)/2 ;
	       //cout << l << " " << r << endl ; 
	       string ans = canbe(mid,n,m) ; 
	       if(ans == "done"){
	           return mid ; 
	       }else if(ans == "dec"){
	           r = mid - 1 ; 
	       }else{
	           l = mid + 1 ;
	       }
	   }

	   return -1 ; 
	}  

link -> https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
