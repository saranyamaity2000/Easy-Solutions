class Solution{
    // Global variables are stored in Data Segment of process. 
    // Global variable's life is until the life of program and 
    // it can be accessed by other files using extern keyword
    // . ... Static variables are initialized only once at the 
    // time of declaration only. Static variables are not accessible
    // by other files using extern keywords.
    

    class Box{
      public:
      int h ,  w , l ; 
      Box(): h(-1) , w(-1) , l(-1) {}
      Box(int h , int w , int l) : h(h) , w(w) , l(l) {}  
    };
    
    public:
    
    static bool comp(Box &a , Box &b){
        return ((a.w * a.l) > (b.w * b.l)) ;  
    }
 
    int maxHeight(int height[],int width[],int length[],int n)
    {
        Box box[3*n] ; 
        int pos = 0 ; 
        for(int i = 0 ; i<n ; i++ ){
            int a = height[i] , b = width[i] , c = length[i] ;
            box[pos++] = Box(a , max(b,c) , min(b,c)) ;
            box[pos++] = Box(b , max(a,c) , min(c,a)) ;
            box[pos++] = Box(c , max(a,b) , min(b,a)) ;
        }
        
        sort( box , box + 3*n , comp) ; 
       
        int dp[3*n] ;
        
        for(int i = 0 ; i<3*n ; i++){
            dp[i] = box[i].h ; 
            
            for(int j = i-1 ; j>=0 ; j--){
                if(box[i].w < box[j].w and box[i].l < box[j].l)
                     dp[i] = max( dp[i] , dp[j] + box[i].h ) ;
            }
        }
        
        return *max_element(dp , dp + 3*n) ;
    }

// OP by SARANYA MAITY , 
// max,min(w,l) concept ref = GFG !  
