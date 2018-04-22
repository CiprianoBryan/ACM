#include<bits/stdc++.h>
using namespace std ;

const int N = 1 << 17 ;
const int INF = 1e9 + 7 ;

/************************************/
long long e2( int x ) {
	return ( 1LL*x*x ) ;
}

/************************************/
bool P[ N + 1 ] ;
vector<int> Pth ;

void sieve( int n ) {
	for( int i = 2 ; i <= n ; i ++ ) {
		P[ i ] = true ;
	}
	for( int num = 2 ; num <= n ; num ++ ) {
		if( !P[ num ] ) continue ;
		Pth.push_back( num ) ;
		for( int mult = 2*num ; mult <= n ; mult += num ) {
			P[ mult ] = false ;
		}
	}
}

/************************************/

int fact( long long num ) {
	int g = 0 ;
	for( int i = 0 ; e2( Pth[ i ] ) <= num ; i ++ ) {
		if( num%Pth[ i ] != 0 ) continue ;
		int div = Pth[ i ] ;
		int exp = 0 ;
		while( num%div == 0 ) {
			num /= div ;
			exp ++ ;
		}
		g = __gcd( g , exp ) ;
	}
	if( num != 1 ) {
		g = 1 ;
	}
	return g ;
}

/************************************/

int main() {
	sieve( N ) ;
	long long x ;
	while( scanf( "%lld" , &x ) == 1 ) {
		if( x == 0 ) break ;
		int p = fact( abs( x ) ) ;
		if( x < 0 ) {
			for( ; p%2 == 0 ; p >>= 1 ) ;
		}
		printf( "%d\n" , p ) ;
	}

	return 0 ;
}

