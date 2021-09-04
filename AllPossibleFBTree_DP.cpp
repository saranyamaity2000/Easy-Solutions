unordered_map< int , vector<TreeNode*> > dp ; 

class Solution {
public:
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if( dp.find(n) != dp.end() ) return dp[n] ;
        
        vector<TreeNode*> ans ; 
     
        if( n == 1) {
            ans.push_back(new TreeNode(0)) ; 
        }
        else if(n % 2 == 1){
            for(int i = 0 ; i<=n-1 ; i++){
                int j = n - 1 - i ; 
                for(auto left : allPossibleFBT(i)) 
                {
                    for(auto right : allPossibleFBT(j)){
                         TreeNode* root = new TreeNode(0) ; 
                         root->left = left ; 
                         root->right = right ; 
                         ans.push_back(root) ; 
                    }
                }
            }
        }
        return dp[n] = ans ; 
    }
};

// its a good problem ! FULL BINARY TREE MEANS EACH node has 
// either 2 children or 0 ; !
