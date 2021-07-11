

#include <bits/stdc++.h>
using namespace std;


#define ALPHABET_SIZE 26

class Solution
{
    public:
  
    bool isUpper(char c){
        return ('A' <= c and c <= 'Z');
    }
    void findAllWords(vector<string> dict, string pattern) 
    {
        int n = dict.size() ; 
        
        int plen = pattern.size() ;

        map<string,multiset<string>> MP ; 

        //why map  ? --->

        // As we were told to solve this using Trie , 
        // result would have been like , sorted ShortForm wise then Sorted String Wise
        // so we have chosen map so that first we can short them key(short_form) wise

        //why multiset ? -->
        // multiset allows you to keep duplicate elements and also in shorted order so
        // within one key you can have multiple duplcates in shorted orders 

        // if you still dont get it , relax , take your time , think again !!! you can do it !
        
        for(int i = 0 ; i<n ; i++){
            int j = 0 ; 
            bool done = 0;
            string s = dict[i] ; 
            string short_form = "";
            
            if(not isUpper(s[0])) continue ;
            for(int k = 0 ; k<s.size() ; k++){
                if( isUpper(s[k]) ){
                     short_form.push_back(s[k]);
                     if(s[k] != pattern[j] )
                        break;
                     else 
                         j++;
                }
                if(j == plen) {
                    done = 1;
                }
            }
            if(done) {
                MP[short_form].insert(s);
            }
        }
        
        if(MP.size() == 0) cout<<"No match found";
        else {
            for(auto i : MP){
                for(auto j : i.second){
                    cout<<j<<" ";
                }
            }
        }
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--) {
	int now;
	cin>>now;
	vector<string> dict(now) ;
	for(int i=0;i<now;i++)
	    cin>>dict[i];

	string pattern;
	cin>>pattern;
	Solution obj;
	obj.findAllWords(dict, pattern);
	    cout<<endl;
}
	return 0;
}
