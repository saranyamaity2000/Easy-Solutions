for(int gap = 0; gap < n; gap++){
            for(int i = 0 ; i < n - gap ; i++){
                int j = i + gap;
                if(gap == 0)
                    P[i][j] = 1; 
                else if(gap == 1)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = ((str[i] == str[j]) & P[i+1][j-1]);
            } 
}

// P[i][j] stores if(i to j) portion is palindrom or not ! 
