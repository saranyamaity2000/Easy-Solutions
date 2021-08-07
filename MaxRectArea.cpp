 int maxArea(int M[MAX][MAX], int n, int m) {
    
        for(int i = 0 ; i<n ; i++){
            height[i][0] = M[i][0] ; 
        }
        for(int i = 0 ; i<m ; i++){
            height[0][i] = M[0][i] ; 
        }
        for(int i = 1 ; i< n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(M[i][j]) 
                  height[i][j] = 1 + height[i-1][j] ; 
                else 
                  height[i][j] = 0 ; 
            }
        }
        int max_area = 0 ; 
        for(int i = 0 ; i<n ; i++){
            max_area = max( max_area , HIST_AREA( i , m ) ) ;
        }
        return max_area ; 
    }
 int HIST_AREA( int row , int m ){
        // current height according to height[row] ;
        stack<int> stk ; 
        pair<int,int> lr_max[m] ; 
    
        for(int i = 0 ; i<m ; i++){
          lr_max[i].l = -1 ; 
          while(not stk.empty() and height[row][stk.top()] >= height[row][i] ){
                int tp = stk.top() ;
                stk.pop() ;
                lr_max[i].l = lr_max[tp].l ; 
          }
          if(lr_max[i].l == -1)  lr_max[i].l = i ; 
          stk.push(i) ; 
        }
        
        while(!stk.empty()) stk.pop() ; 
        
        for(int i = m-1 ; i>=0 ; i--){
          lr_max[i].r = -1 ; 
          while(not stk.empty() and height[row][stk.top()] >= height[row][i] ){
                int tp = stk.top() ; 
                stk.pop() ;
                lr_max[i].r = lr_max[tp].r ; 
          }
          if(lr_max[i].r == -1)  lr_max[i].r = i ; 
          stk.push(i) ; 
        }
        int max_area = -1 ; 
        for(int i = 0 ; i<m ; i++){
            max_area = max( (lr_max[i].r - lr_max[i].l + 1)*height[row][i] , max_area ) ;  
        }
        return max_area ; 
 }
