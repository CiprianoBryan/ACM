#include<bits/stdc++.h>
using namespace std ;

const int N = 5e4 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
int phi[ N + 1 ] ;

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
int cant[ N + 1 ] ;

int main() {
	sievePhi( N ) ;
	for( int i = 2 ; i <= N ; i ++ ) {
		cant[ i ] = cant[ i - 1 ] + phi[ i ] ;
	}
	int n ;
	while( scanf( "%d" , &n ) == 1 ) {
		if( n == 0 ) break ;
		printf( "%d\n" , 2*cant[ n ] + 1 ) ;
	}

	return 0 ;
}

