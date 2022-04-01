int swapBits(int x, int p1, int p2, int n)
    {
        int a = (x >> p1) & ((1 << n) - 1) ; 
        // getting those n bits from point p1 
        
        int b = (x >> p2) & ((1 << n) - 1) ;
        // getting those n bits from point p2 
        
        int c = a ^ b ; 
        // doing xor ! 
        
        x ^= (c << p1) ; 
        x ^= (c << p2) ;
        // xor c back to main position so a become b
        // and b become a
        
        return x ; 
    }
