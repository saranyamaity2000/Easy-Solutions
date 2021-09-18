// BEAUTIFUL METHOD BY RECURSION / DEVIDE CONQUER !  

Node* merge(Node* a, Node* b)
    {
         if( not a ) return b ; 
         else if(not b) return a; 
         
         Node* res ; 
         
         if(a->data < b->data)
         {
             res = a ; 
             a = a->next ; 
         }
         else
         {
             res = b ;
             b = b->next ; 
         }
         
         res->next = merge(a,b) ;
         
         return res ; 
    }
    
    Node* mergeKLists(Node* arr[], int k)
    {
         int n = k ;
         
         int last = n-1 ; 
         
         while(last)
         {
             int l = 0 , h = last ; 
             while(l<h)
             {
                 arr[l] = merge(arr[l++],arr[h--]) ;
             }
             last = h ; 
         }
         
         return arr[0] ; 
    }

// METHOD -> HEAP  ;

#define ff first
#define ss second

struct comp{
    bool operator()(pair<int,int> &a , pair<int,int> &b) // ff = 
   {
     return a.ff > b.ff ; 
   }
}; 


class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node *arr[], int n)
    {
           priority_queue<pair<int,int> , vector<pair<int,int>> , comp> pq ;
           
           Node* head = new Node(0) ; 
           Node* temp = head ; 
           
           for(int i = 0 ; i<n ; i++)
           {
               pq.push({arr[i]->data,i}) ; 
           }
           
           while(not pq.empty())
           {
               int tp = pq.top().ff ;
               int ll_no = pq.top().ss ; 
               
               pq.pop() ;
               
               arr[ll_no] = arr[ll_no]->next ; 
               
               if(arr[ll_no])
               {
                   pq.push({arr[ll_no]->data, ll_no}) ; 
               }
               
               temp->next = new Node(tp);
               temp = temp->next ;
               
           }
           
           head = head->next ; 
           return head ; 
           
    }
};
