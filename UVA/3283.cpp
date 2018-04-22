#include<bits/stdc++.h>
using namespace std ;

const int N = 6e4 + 2 ;
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
	int sd = 1 ;
	while( ddo[ num ] ) {
		int div = ddo[ num ] ;
		int prod = 1 ;
		while( num%div == 0 ) {
			num /= div ;
			prod *= div ;
		}
		prod *= div ;
		sd *= ( prod - 1 )/( div - 1 ) ;
	}
	if( num != 1 ) {
		sd *= num + 1 ;
	}
	return sd ;
}

int main() {
	sieve( N - 1 ) ;
	printf( "PERFECTION OUTPUT\n" ) ;
	int num ;
	while( scanf( "%d" , &num ) == 1 ) {
		if( num == 0 ) break ;
		printf( "%5d  " , num ) ;
		int sd = fact( num ) - num ;
		if( sd == num ) printf( "PERFECT\n" ) ;
		if( sd < num ) printf( "DEFICIENT\n" ) ;
		if( sd > num ) printf( "ABUNDANT\n" ) ;		
	}
	printf( "END OF OUTPUT\n" ) ;

	return 0 ;
}
