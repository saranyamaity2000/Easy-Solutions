public:
    int maxCandy(int arr[], int n) 
    { 
        
        int i= 0 , j = n-1 ; 
        
        int maxi = INT_MIN ; 
        
        while( i < j)
        {
            int curr = min(arr[i],arr[j]) * ( j - i - 1) ;
            maxi = max(curr, maxi) ; 
            
            if( arr[i] > arr[j] )
            {
                j-- ; 
            }
            else if(arr[i] < arr[j])
            {
                i++ ; 
            }
            else 
            {
                i++ ; 
                j-- ; 
            }
        }
        
        return max(maxi,0) ; 
        
    }   
