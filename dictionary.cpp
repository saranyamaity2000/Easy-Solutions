// Program to implement DICTIONARY features 
// like insertion , deletion , search , prefix_search
// worst case timecomplexity O(|S|) where S is the given string ! 
// for prefix_search the time complexity is not O(|S| ) , think why ! 
// look at the function of prefix search and findout what can be the time complexity !

// Tip : You can modify the function and can create prefix_delete

// if you are not aware of these terms then please search it on google 
// and gather information ! 

// I HAVE SHOWN only the functions ! learn them and feel them and implement on your own ! 

#include <bits/stdc++.h>
using namespace std;

//-------------------------- USED MACROS -------------------------------------->
#define  pb    emplace_back
#define  v(t) vector<t>

#define  loop(i,a,b) for(ll i = a;i<=b;i++)
#define  print_container(box) for(auto i : box){ cout<<i<<" "; }

//<-----------------  CODE STARTS FROM HERE BY < SARANYA MAITY > ------------------->


// <--------USEFUL FUNCTIONS and DS HERE ----------->


 struct TrieNode{
      TrieNode* arr[26];
      bool isend;
      TrieNode(){
         isend = false ; 
         for(int i = 0 ; i<26 ; i++){
           arr[i] = NULL ; 
         }
      }
 };

 void findall(string s , v<string>& vec , TrieNode* dict){
      for(int i = 0 ; i<26 ; i++){
          if(dict->arr[i]){
               s.push_back('a'+ i);
               if(dict->arr[i]->isend) vec.pb(s);
               findall(s , vec , dict->arr[i]);
               s.pop_back();
          }
      }
 }
 v<string> prefixsearch(string s,TrieNode* dict){
      v<string> vec ; 
      TrieNode *temp = dict ; 
      for(int i = 0 ; i<s.size() ; i++){
         temp = temp->arr[s[i]-'a'] ; 
         if(temp == NULL) return vec ; 
      }
      if(temp->isend) vec.pb(s);

      findall(s , vec , temp);
      return vec ; 
 }

 bool deleteword(string s, TrieNode* dict){
      TrieNode* temp = dict ; 
      for(int i = 0 ; i<s.size() ; i++){
          temp = temp->arr[s[i]-'a'] ; 
          if(temp == NULL) return 0 ; 
      }
      if(temp->isend) {
        temp->isend = false ; 
        return true ;
      }
      return false ; 
 }

 bool wordinsert(string s,TrieNode* dict){
     TrieNode *temp = dict ; 
     int n = s.size() ;
     bool ins = false ; 
     for(int i = 0 ; i< n ; i++){
         if(temp->arr[s[i]-'a'] == NULL){
           temp->arr[s[i]-'a'] = new TrieNode();
         }
         temp = temp->arr[s[i]-'a'] ; 
     }
     if(temp->isend == false) {
      ins = true ;
      temp->isend = true ;
     }
     return ins ; 
 }

 bool wordsearch(string s,TrieNode *dict){
   TrieNode* temp = dict ; 
   int n = s.size() ; 
   for(int i = 0 ; i<n; i++){
       temp = temp->arr[s[i]-'a'] ;
       if(temp == NULL) return false ;
   }
   if(temp->isend) return true;
   return false;
 }



//<---------------------- END --------------------->