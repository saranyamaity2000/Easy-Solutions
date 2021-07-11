

 //Solution to this problem  is super easy! 
//if you want to have a CLEAR idea then please go through 
//Trie DataStructure in GFG articles. 


#include <bits/stdc++.h>
using namespace std;

struct Node{ // TrieNode creation ( you must know the basics for understanding )
    bool isEndOfWord;
    int count1;
    map<char, Node *> mp;
};

Node *newNode(){
    Node *temp = new Node();
    temp->isEndOfWord = false;
    return temp;
}


class Solution
{
    
    public:
    void insert(string s , Node* dict ){ 
        int n = s.size() ; 
        Node* temp = dict ; // created a dummy node so that main dict remains same 
        
        bool done = 0 ; // to check if we have already printed or not 
        
        string help = "" ; // help to keep track of how far we have proceeded  
        
        for(int i = 0 ; i<n ; i++){ // now traversing character wise 
            
           help.push_back(s[i]) ; 
           if(temp->mp[s[i]] == NULL) // if this node was NULL 
            {

               if(not done){ // if we have not printed untill now 
               done = 1 ; // make sure to turn this on so that we dont print this again !
               cout<<help<<endl;
               }
               temp->mp[s[i]] = newNode() ; 
            }
            temp = temp->mp[s[i]]; 
        }
        
        // now 2 case can happen interm of PRINT case

        // and 2 Parmanent case , that is making isEndOfWord = true
        // and increamenting the count variable

        
        //print cases here 
        if(temp->isEndOfWord) cout<<help<<" "<<temp->count1+1<<endl;
        else if(not done) cout<<help<<endl;
        
        //parmanent cases here so out of the ifelse 
        temp->isEndOfWord = true; 
        temp->count1++;
    }

    void check(string *arr, int n){
       Node *dict = newNode() ; 
       for(int i = 0 ; i<n; i++){
           insert(arr[i] , dict ) ; 
       }
    }

};


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        Solution obj;
        obj.check(arr,n);
    }
    return 0;
}