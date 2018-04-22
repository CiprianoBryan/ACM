#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline int Sqrt( long double n ) {
	return sqrt( 1.*n ) ;
}

int main() {
	long long n ;
	while( cin >> n ) {
		if( n == 0 ) break ;
		cout << n - ( Sqrt( n ) + Sqrt( n/2. ) ) << '\n' ;
	}

	return 0 ;
}
