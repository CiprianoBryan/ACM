#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
bool P[ N ] ;
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

int solve( int num ) {
	int cant = 0 ;
	for( int i = 0 ; Pth[ i ] <= num/2 ; i ++ ) {
		if( P[ num - Pth[ i ] ] ) {
			cant ++ ;
		}
	}
	return cant ;
}

int main() {
	sieve( 1 << 16 ) ;
	int num ;
    while( scanf( "%d" , &num ) == 1 ) {
    	if( num == 0 ) break ;
    	printf( "%d\n" , solve( num ) ) ;
	}

    return 0 ;
}
