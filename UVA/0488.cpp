#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6 ;
const int INF = 1e9 + 7 ;

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
int fact( int num ) {
	int sum = 0 ;
	while( ddo[ num ] ) {
		int exp = 0 ;
		int div = ddo[ num ] ;
		while( num%div == 0 ) {
			num /= div ;
			sum ++ ;
		}
	}
	if( num != 1 ) {
		sum ++ ;
	}
	return sum ;
}

/************************************/
int sum[ N + 1 ] ;

int main() {
	sieve( N ) ;
	for( int i = 2 ; i <= N ; i ++ ) {
		sum[ i ] = sum[ i - 1 ] + fact( i ) ;
	}
	int num ;
	while( scanf( "%d" , &num ) == 1 ) {
		printf( "%d\n" , sum[ num ] ) ;
	}

	return 0 ;
}

