#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
long long e2( int x ) {
	return ( 1LL*x*x ) ;
}

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
long long solve( int num ) {
	long long prod = 1 ;
	for( int i = 0 ; e2( Pth[ i ] ) <= num ; i ++ ) {
		if( num%Pth[ i ] != 0 ) continue ;
		int div = Pth[ i ] ;
		int exp = 0 ;
		while( num%div == 0 ) {
			num /= div ;
			exp ++ ;
		}
		prod *= 2*exp + 1 ;
	}
	if( num != 1 ) {
		prod *= 3 ;
	}
	return ( prod + 1 )/2 ;
}

/************************************/

int main() {
	sieve( 1e5 ) ;
	int num ;
	while( scanf( "%d" , &num ) == 1 ) {
		if( num == 0 ) break ;
		printf( "%d %lld\n" , num , solve( num ) ) ;
	}

	return 0 ;
}

