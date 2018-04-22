#include<bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 2 ;
const int mod = 1e9 + 7 ;
const int mod2 = 1e9 + 6 ;
const int mod3 = 5e8 + 3 ;

/************************************/
inline int mult( int a , int b , int mod ) {
	return ( 1LL*a*b )%mod ;
}

int Pow( int b , int e , int mod ) {
	int prod = 1 ;
	for( ; e ; e >>= 1 ) {
		if( e&1 ) prod = mult( prod , b , mod ) ;
		b = mult( b , b , mod ) ;
	}
	return prod ;
}

inline int InverseMod( int num , int mod ) {
	return Pow( num , mod - 2 , mod ) ;
}

/************************************/
int F[ N ] ;

void buildF( int n ) {
	F[ 0 ] = 1 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		F[ i ] = mult( F[ i - 1 ] , i , mod3 ) ;
	}
}

/************************************/

int main() {
	buildF( N - 1 ) ;
	int t ;
	cin >> t ;
	int a , b , n ;
	while( t -- ) {
		scanf( "%d %d %d" , &a , &b , &n ) ;
		int x = mult( F[ 2*n ] , InverseMod( mult( F[ n ] , F[ n ] , mod3 ) , mod3 ) , mod3 ) ;
		x = mult( x , 2 * InverseMod( 2 , mod3 ) , mod2 ) ;
		x = Pow( x , b , mod2 ) ;
		printf( "%d\n" , Pow( a , x , mod ) ) ;
	}

	return 0 ;
}

