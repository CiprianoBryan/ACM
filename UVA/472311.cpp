#include<bits/stdc++.h>
using namespace std ;

const long long N = 2e10 ;
const int M = 1e6 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
int phi[ M ] ;

void sievePhi( int n ) {
	for( int num = 1 ; num <= n ; num ++ ) {
		phi[ num ] = num ;
	}
	for( int num = 2 ; num <= n ; num ++ ) {
		if( phi[ num ] != num ) continue ;
		for( int mult = num ; mult <= n ; mult += num ) {
			phi[ mult ] -= phi[ mult ]/num ;
		}
	}
}

/************************************/
long long acc[ M ] ;

void init() {
	sievePhi( M - 1 ) ;
	acc[ 1 ] = 2 ;
	for( int i = 2 ; acc[ i - 1 ] <= N ; i ++ ) {
		acc[ i ] = acc[ i - 1 ] + phi[ i ] ;
	}
}

int main() {
	init() ;
	long long k ;
	while( cin >> k ) {
		if( k == 0 ) break ;
		int d = 1 ;
		for( ; acc[ d ] < k ; d ++ ) ;
		int place = k - acc[ d - 1 ] ;
		for( int num = 0 ; num <= d ; num ++ ) {
			if( __gcd( num , d ) == 1 ) place -- ;
			if( place == 0 ) {
				printf( "%d/%d\n" , num , d ) ;
				break ;
			}
		}
	}

	return 0 ;
}

