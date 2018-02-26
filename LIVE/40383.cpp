#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/

int main() {
	int t , n , x ;
	cin >> t ;
	while( t -- ) {
		cin >> n ;
		int ans = 0 ;
		bool allLessEqual1 = true ;
		for( int i = 0 ; i < n ; i ++ ) {
			scanf( "%d" , &x ) ;
			ans ^= x ;
			if( x > 1 ) {
				allLessEqual1 = false ;
			}
		}
		if( ( ans == 0 ) == !allLessEqual1 ) printf( "Brother\n" ) ;
		else printf( "John\n" ) ;
	}

	return 0 ;
}