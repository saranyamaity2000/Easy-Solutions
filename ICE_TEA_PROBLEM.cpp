

// A: Ice Cream Store
// You've come to your favorite store Infinitesco to buy some ice tea.
//The store sells ice tea in bottles of different volumes at different costs.
// Specifically, a 0.25-liter bottle costs Q yen, a 0.5-liter bottle costs 
//H yen, a 1-liter bottle costs S yen, and a 2-liter bottle costs D yen. 
//The store has an infinite supply of bottles of each type.
//You want to buy exactly N liters of ice tea. 
//How many yen do you have to spend?

void solve()
{
	
	ll a , b , c , d ; 

	cin >> a >> b >> c >> d ; 

	ll n ; 

	cin >>n ; 

	ll buy2 = min({8*a, 4*b , 2*c , d}) * (n/2) ; 
	ll buy1 = min({4*a, 2*b , c}) * (n%2) ;

	cout << buy2 + buy1 ;  

}



//<-------------------------------->
