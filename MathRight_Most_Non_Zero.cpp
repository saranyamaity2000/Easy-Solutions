int rightmostNonZeroDigit(int n, int arr[]){
        
        for(int i = 0 ; i<n ; i++){
            if(arr[i] == 0) return -1 ; 
        }
        
        int fives = 0 ; 
        
        for(int i = 0 ; i<n ; i++){
            
            while(arr[i] and arr[i]%5 == 0){
                fives++ ; 
                arr[i] /= 5 ; 
            }
        }
        
        for(int i = 0 ; i<n ; i++){

            while(fives and (arr[i] > 0) and (arr[i]%2 == 0)){
                fives-- ;  
                arr[i] /= 2 ; 
            }
        }
        
        int ans = 1; 
        for (int i = 0; i < n; i++) { 
            ans = (ans * arr[i] % 10) % 10; 
        }
        
        if(fives) ans = (ans * 5) % 10 ; 
        
        return ans ; 
        
    }
