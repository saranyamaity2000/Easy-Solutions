class solution
{
	public:
	    using ll = int ;
	    vector<string> codes ; 
	    struct Node{
	        char c ; 
	        ll f ; 
	        Node* left ;
	        Node* right ; 
	        Node(char a , ll x){
	            c = a ; 
	            f = x ; 
	            left = right = nullptr ; 
	        }
	    }; 
	    struct comp{
	        bool operator()(Node* a, Node* b){
	            return (a->f > b->f) ; 
	        }
	    }; 
	    void getcodes(Node* root , string code){
	        if(root->c != '$'){
	           codes.push_back(code) ; 
	           return ; 
	        }
	        getcodes(root->left , code + "0"); 
	        getcodes(root->right , code + "1") ; 
	    }
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    priority_queue<Node* , vector<Node*> , comp> pq ; 
		    for(ll i = 0 ; i<n ; i++){
		        Node* x = new Node(s[i] , f[i]) ; 
		        pq.push(x) ; 
		    }
		    Node* root = NULL ; 
		    while(pq.size() >= 2){
		        Node* a = pq.top(); 
		        pq.pop() ; 
		        Node* b = pq.top() ; 
		        pq.pop() ;
		        Node* c = new Node('$', a->f + b->f) ; 
		        c->left = a ; 
		        c->right = b ; 
		        pq.push(c) ; 
		    }
		    root = pq.top() ; 
		    pq.pop() ; 
		    string code = "" ; 
		    getcodes(root, code) ; 
		    return codes ; 
		}
};