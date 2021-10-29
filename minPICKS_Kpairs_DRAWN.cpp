int find_min(int a[], int n, int k) {
        
        //check if possible pair are there or not 
        int tp = 0 ; 
        for(int i = 0 ; i<n ; i++) tp += a[i]/2 ; 
        if(tp < k) return -1 ; 

        // take 1 from everyone
        for(int i = 0 ; i<n ; i++) a[i]-- ; 
        int mini = n ;
    
        // our goal is to pick last element as no benifit to pair increament
        // (think why)
        for(int i = 0 ; i<n ; i++)
        {
            if(a[i] == 0) continue ; 
            
            int take = a[i] - (a[i]&1) ; 
            
            int pairs = (take + 1)/2 ; 
            
            if(pairs >= k) return (mini +  2*k - 1) ; 
    
            k -= pairs ; 
            mini += take ; 
        }
        
        // remaining k pairs we will obviously get , that is 
        return (mini + k) ; 
        
    }

// problem link -> https://practice.geeksforgeeks.org/problems/620fb6456d6515faddd77050dfbf2821d7a94b8a/1#
