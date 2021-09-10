#include<bits/stdc++.h>
using namespace std ;

int main() {
  int k ;
  cin >> k ;
  int primes[k] ;
  for (int i = 0 ; i < k ; i++) cin >> primes[i] ;
  int n ;
  cin >> n ;

  int dp[n + 1] ;
  dp[1] = 1;

  int pointers[k];
  fill(pointers, pointers + k, 1) ;

  for (int i = 2; i <= n; i++) {
    int mini = INT_MAX ;
    for (int j = 0; j < k ; j++) {
      mini = min(mini, primes[j] * dp[pointers[j]]);
    }
    dp[i] = minai;
    for (int j = 0; j < k ; j++) {
      if (mini ==  (primes[j] * dp[pointers[j]])) {
        pointers[j]++;
      }
    }
  }

  cout << dp[n];
  return 0 ;

}
