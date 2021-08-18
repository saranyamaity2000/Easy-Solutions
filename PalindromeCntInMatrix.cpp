#define ll long long int


class Solution {
  
  public:
	ll mod = 1e9 + 7;
	ll modadd(ll x, ll y) {
		return ((x%mod) + (y%mod))%mod;
	}
    
    bool safe(int n, int m, int i, int j) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }
    
    ll solve(vector<vector<char>> &matrix, int starti, int startj, int endi, int endj, map< pair< pair<int,int>,pair<int,int> >, ll> &dp) {
        int n = matrix.size(), m = matrix[0].size();
        
        
        if ( not safe(n, m, starti, startj) || not safe(n, m, endi, endj))
            return 0;
        
        if (starti > endi or startj > endj)
            return 0;
        
        if (matrix[starti][startj] != matrix[endi][endj])
            return 0;
        
        if (abs((starti - endi) + (startj - endj)) <= 1) 
            return 1;
        
        pair< pair<int,int>,pair<int,int> > combo = pair<pair<int,int>,pair<int,int>>
                                                    (pair<int,int>(starti, startj), pair<int,int>(endi, endj));
                                                    
        
        if(dp.count(combo))
            return dp[combo];
            
        
        ll cnt = 0;
        cnt = modadd(cnt, solve(matrix, starti + 1, startj, endi - 1, endj, dp));
        cnt = modadd(cnt, solve(matrix, starti + 1, startj, endi, endj - 1, dp));
        cnt = modadd(cnt, solve(matrix, starti, startj + 1, endi - 1, endj, dp));
        cnt = modadd(cnt, solve(matrix, starti, startj + 1, endi, endj - 1, dp));
        
        
        return dp[combo] = cnt;
    }
    
    int countPalindromicPaths(vector<vector<char>>matrix){
    	int n = matrix.size();
    	int m = matrix[0].size();
    	map<pair<pair<int,int>,pair<int,int>>,ll> dp;
    	return (int)(solve(matrix, 0, 0, n-1, m-1, dp)%mod);
    }
};

# Not my approach !! one of th best problem ! 
