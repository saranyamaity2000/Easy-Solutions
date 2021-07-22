bool isSumTree(Node* root)
    {
         if(root == NULL) return 1; 
         
         bool ok1 = isSumTree(root->left) ; 
         bool ok2 = isSumTree(root->right) ; 
         
         int l = 0 , r = 0 ; 

         bool any = (root->left || root->right) ; 
         
         if(root->left) 
             l = root->left->data ; 
         if(root->right) 
             r = root->right->data ;
         
         bool ok3 = any ? (l+r == root->data) : 1 ; 
         
         root->data += (l+r) ; 
         
         return (ok1 and ok2 and ok3) ; 
    }

// done by SARANYA MAITY .
