#include <bits/stdc++.h>
using namespace std;

#define N 9  

#define M 10

class Solution 
{
    public:
    void fillup(bool arr[N][M]){
        for(int i = 0 ; i<9 ; i++){
            for(int j= 0 ; j<10 ; j++){
                arr[i][j] = 0 ; 
            }
        }
    }
    
    int square_pos(int i , int j ){
        return (i/3) + 3*(j/3) ;  
    }
    
    bool canbe(int grid[N][N] , vector<pair<int,int>> left , int index , bool row[N][M] , bool col[N][M] , bool square[N][M]){
        
        if(index == left.size()) return 1;
        
        int i = left[index].first;
        int j = left[index].second;
        int sp = square_pos(i,j);
        
        bool possible = 0 ;
        
        for(int k = 1 ; k<=9 ; k++){
            
            if( row[i][k] or col[j][k] or square[sp][k]) continue;
            
            row[i][k] = col[j][k] = square[sp][k] = 1;
            
            grid[i][j] = k ; 
            
            possible |= canbe(grid , left , index+1 , row , col , square) ;
            
            if(possible) return 1;
            
            row[i][k] = col[j][k] = square[sp][k] = 0;
        }
        
        return possible;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        bool row[N][M]; 
        bool col[N][M]; 
        bool square[N][M]; 
        fillup(col);
        fillup(row);
        fillup(square);
        
        vector<pair<int,int>> left ;
        
        for(int i = 0 ; i< N ; i++){
            for(int j = 0 ; j<N ; j++){
                int k = grid[i][j] ;
                int sp = square_pos(i,j);
                if(k != 0){
                    row[i][k] = 1;
                    col[j][k] = 1;
                    square[sp][k] = 1;
                }
                else{
                    left.push_back(make_pair(i,j));
                }
            }
        }
        
        return canbe( grid , left , 0 , row , col ,square);
    }
    void printGrid (int grid[N][N]) 
    {
      for(int i = 0 ; i<N ; i++){
          for(int j = 0 ; j<N ; j++){
              cout<<grid[i][j]<<" ";
          }
      }
    }
};



int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
