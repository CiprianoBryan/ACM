#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
int ddo[ N ] ;

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
int fact( int num ) {
	int cant = 0 ;
	while( ddo[ num ] ) {
		int exp = 0 ;
		int div = ddo[ num ] ;
		if( num%div == 0 ) {
			cant ++ ;
		}
		while( num%div == 0 ) {
			num /= div ;
			exp ++ ;
		}
		if( exp > 1 ) {
			return -1 ;
		}
	}
	if( num != 1 ) {
		cant ++ ;
	}
	return cant ;
}


/************************************/
int M[ N ] ;
int mu[ N ] ;

int main() {
	sieve( N - 1 ) ;
	M[ 1 ] = 1 ;
	for( int i = 2 ; i <= N ; i ++ ) {
		M[ i ] = M[ i - 1 ] ;
		int cant = fact( i ) ;
		if( cant == -1 ) continue ;
		mu[ i ] = (cant&1) ? -1 : 1 ;
		M[ i ] += mu[ i ] ;
	}
	int n ;
	while( scanf( "%d" , &n ) == 1 ) {
		if( n == 0 ) break ;
		printf( "%8d%8d%8d\n" , n , mu[ n ] , M[ n ] ) ;
	}

	return 0 ;
}

