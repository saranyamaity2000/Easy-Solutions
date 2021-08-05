
// Q ->Given a sorted array A[] of N positive integers 
//  having all the numbers occurring exactly twice,
//  except for one number which will occur only once. 
//  Find the number occurring only once.


// I have only added the function that is main ! 

int search(int A[], int N){
	    if(A[0] != A[1]) return A[0] ; 
	    if(A[N-1] != A[N-2]) return A[N-1] ; 
	    int l = 0 ; int h = N - 1; 
	    int ans = -1;
	    while(l<=h){
	        int mid = l + (h - l)/ 2 ; 
	        if(A[mid] > A[mid-1] and A[mid] < A[mid+1]) {
	           return A[mid] ; 
	        }
	        else if(( A[mid] == A[mid+1] and mid%2 == 0) ||
	                   ( A[mid] == A[mid-1] and mid%2 == 1)) // think why i have added this solution 
	           l = mid + 1; 
	        else 
	           h = mid -1 ;  
	    }
	}
// the main condition in the else if case added !
// because if(mid%2) == 0 , means (mid+1)%2 == 1 , that is 
// no of elements present upto that arr[mid] element 
// is (mid + 1) so odd no of elements present , so if A[mid+1] 
// is equal to A[mid] , it means total right portion is fully sorted
// total even no elements present , and if the desired element 
// that we want was the ans then len should have been odd considering
// that desired/wanted element is not paired ! 
