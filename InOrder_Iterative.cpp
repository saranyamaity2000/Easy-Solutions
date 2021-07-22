 //I HAVE WRITTEN MY STYLE OF
// APPROACH FOR DOING ITERATIVE TRAVELSAL
 // USING STACK of PAIR !

 vector<int> inOrder(Node* root)
    {
       vector<int> vec ; 
       if(root == NULL) return vec ; 
      stack<pair<Node*,bool>> stk ; 
      stk.push({root,0}) ; 
      
      while(not stk.empty()){
          while(stk.top().second == 0){
              Node* tp = stk.top().first ; 
              stk.pop() ; 
              if(tp->right) stk.push({tp->right,0}) ; 
              stk.push({tp,1});
              if(tp->left) stk.push({tp->left,0}) ; 
          }
          while(!stk.empty() and stk.top().second == 1){
              vec.push_back(stk.top().first->data);
              stk.pop() ; 
          }
      }
      return vec ; 
    }