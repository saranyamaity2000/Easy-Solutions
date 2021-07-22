   node* reversell(node* head, node* &tail , node* &bhead){
        
        if( head == tail ) return head;  
        if(!head or !head->next) return head; 
    
        node* prev = NULL ; 
        node* curr = head ; 
        node* nxt = head->next ; 
        while(curr != tail){
            curr->next = prev ; 
            prev = curr ; 
            curr = nxt ; 
            if(nxt != tail) nxt= nxt->next ; 
        }
        bhead->next = prev ; 
        head->next = tail ; 
        return head ; 
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        
        // add dummy node 
        node* tmp = new node(0) ;
        tmp->next = head ; 
        head = tmp ; 
        // end adding dummy node ! 
        
        // new start !
        node* temp  = head->next ; 
        int c = 0 ; 
        
        // forming btail(before tail) , bhead(before head) and hd(curr head);
        node* btail = NULL ; 
        node* bhead = head ; 
        node* hd = head->next  ;
        
        // main 
        while(temp){
            if(c == k) {
                bhead = reversell(hd , temp , bhead) ; 
                // or you can do , bhead = hd ;
                // both are doing the same task ;
                hd = temp ; 
                c = 0 ; 
            }
            btail = temp ; 
            temp = temp->next ; 
            c++ ; 
        }
        
        //if some portion left to be reversed ; 
        reversell(hd , temp , bhead) ; 
        
        //fix head
        head = head->next ;
        
        return head ;
    }

   // DONE BY SARANYA MAITY 
