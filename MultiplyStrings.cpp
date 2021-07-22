 int ctoi(char c) {
        return (c - '0') ;
    }
    char itoc(int n){
        return (n + '0') ; 
    }
    string mulstring(string s , char num){
       
       int carry = 0 ; 
       for(int i = s.size()-1 ; i>=0 ; i-- ){
           int val = ctoi(s[i])*ctoi(num) + carry;
           carry = val / 10 ; 
           val = val%10 ; 
           s[i] = itoc(val) ;
       }
       if(carry)
           s = (to_string(carry) + s); 
       return s; 
    }
    string addstring(string s1 , string s2){
       
        
        reverse(s1.begin(),s1.end()) ; 
        reverse(s2.begin(),s2.end()) ;
       
        int n1 = s1.size() ; 
        int n2 = s2.size() ;
        
           
        int carry = 0 ; 
        string ans = "" ; 
        int i = 0 ; 
        while(i< max(n1,n2) ){
            int ff = (i<n1? ctoi(s1[i]) : 0) ;
            int ss = (i<n2? ctoi(s2[i]) : 0) ;
            int val = ff + ss + carry ; 
            carry = val/10 ; 
            val= val%10 ; 
            ans.push_back(itoc(val)) ; 
            i++;
        }
        if(carry) ans.push_back(itoc(carry)) ; 
        reverse(ans.begin(),ans.end()) ;
       
        return ans ; 
    }
    
    string multiplyStrings(string s1, string s2) {
        string prev = "0" ; 
        char sign = '+' ; 
        
        if((s1[0] == '-') ^ (s2[0] == '-')) 
           sign = '-' ; 
           
        if(s1[0] == '-') s1 = s1.substr(1) ; 
        if(s2[0] == '-') s2 = s2.substr(1) ; 
        
        int k = 0 ; 
        while(k<s1.size()){
            if(s1[k] !='0') break;
            k++;
        }
        s1 = s1.substr(k);
        
        k = 0;
         while(k<s2.size()){
            if(s2[k] !='0') break;
            k++;
        }
        s2 = s2.substr(k) ;
        
        if(s1 == "" || s2 == "") return "0" ; 
        
        int n = s1.size() ; 
        for(int i = n-1 ; i>=0 ; i--){
            int ps = prev.size() ; 
            prev = addstring( prev.substr(0,ps-(n-i-1)) , mulstring(s2 ,s1[i]) ) + prev.substr(ps-(n-i-1));
        }
        if(sign == '-') return (sign + prev) ; 
        return prev ; 
    }
  // DONE by Saranya Maity 
