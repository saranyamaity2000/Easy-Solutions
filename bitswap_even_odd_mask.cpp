ll swapBits(ll n)
    {
       int pow2 = 1 ; 
       
       ll evenmask = 0 ;
       
       for(int i = 0 ; i<32 ; i++)
       {
          if(i%2) evenmask += pow2 ; 
          pow2 *= 2 ; 
       }
       
       ll oddmask = evenmask >> 1 ;
       
       
       return ((n & evenmask)>>1) + (( n & oddmask)<<1) ; 
       
}
