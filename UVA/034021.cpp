#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline int Ceil( int a , int b ) {
	return a/b + ( a%b != 0 ) ;
}

/************************************/
int ddo[ N + 1 ] ;

void sieve( int n ) {
	for( int i = 4 ; i <= n ; i += 2 ) {
		ddo[ i ] = 2 ;
	}
	for( int num = 3 ; num*num <= n ; num += 2 ) {
		if( ddo[ num ] ) continue ;
		for( int dor = num*num ; dor <= n ; dor += 2*num ) {
			ddo[ dor ] = num ;
		}
	}
}

/************************************/
int sigma[ N + 1 ] ;
int SD[ N + 1 ] ;

void build( int num ) {
	int x = num ;
	SD[ x ] = 1 ;
	sigma[ x ] = 1 ;
	while( ddo[ num ] ) {
		int div = ddo[ num ] ;
		int exp = 0 ;
		int prod = 1 ;
		while( num%div == 0 ) {
			num /= div ;
			prod *= div ;
			exp ++ ;
		}
		prod *= div ;
		sigma[ x ] *= exp + 1 ;
		SD[ x ] *= ( prod - 1 )/( div - 1 ) ;
	}
	if( num != 1 ) {
		sigma[ x ] <<= 1 ;
		SD[ x ] *= num + 1 ;
	}
}

/************************************/

int main() {
	sieve( N ) ;
	for( int i = 1 ; i <= N ; i ++ ) {
		build( i ) ;
	}
	int t ;
	cin >> t ;
	int a , b , k ;
	while( t -- ) {
		scanf( "%d %d %d" , &a , &b , &k ) ;
		long long g = 0 , h = 0 ;
		for( int q = Ceil( a , k ) ; q <= b/k ; q ++ ) {
			g += sigma[ q*k ] ;
			h += SD[ q*k ] ;
		}
		printf( "%lld %lld\n" , g , h ) ;
	}

	return 0 ;
}

