#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
long long C[ 22 ][ 22 ] ;
long long D[ 22 ] ;

void build() {
	for( int i = 1 ; i <= 20 ; i ++ ) {
		for( int j = 0 ; j <= i ; j ++ ) {
			if( i == j || j == 0 ) C[ i ][ j ] = 1 ;
			else C[ i ][ j ] = C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ] ;
		}
	}
	D[ 0 ] = 1 , D[ 1 ] = 0 ;
	for( int i = 2 ; i <= 20 ; i ++ ) {
		D[ i ] = ( i - 1 )*( D[ i - 1 ] + D[ i - 2 ] ) ;
	}
}

int main() {
	build() ;
	int n , m ;
	while( scanf( "%d %d" , &n , &m ) == 2 ) {
		long long ans = 0 ;
		for( int i = 0 ; i <= m ; i ++ ) {
			ans += C[ n ][ i ]*D[ n - i ] ;
		}
		printf( "%lld\n" , ans ) ;
	}

	return 0 ;
}

