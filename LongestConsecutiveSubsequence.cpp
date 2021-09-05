int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set<int> s ; 
        for(int i = 0 ; i<n ; i++){
            s.insert(arr[i]) ; 
        }
        int cnt = 0 ; 
        for(int i = 0 ; i<n ; i++){
            // to check if its the begining of the series
            if(s.find(arr[i]-1) == s.end()){ 
                int ele = arr[i] ; 
                while(s.find(ele+1) != s.end()){
                    ele++ ;
                }
                cnt = max(cnt , ele- arr[i] + 1) ; 
            }
        }
        return cnt ; 
    }
