//process1-> 

 sort(A.begin(), A.end());
 A.erase(unique(A.begin(), A.end()), A.end());

//prcoess2->

set<int> S(A.begin(),A.end()) ;
A.clear();
for(auto i : S) A.push_back(i);
