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
int Pow( int b , int e ) {
	int prod = 1 ;
	for( ; e -- ; prod *= b ) ;
	return prod ;
}

int fact( int a , int c ) {
	int b = 1 ;
	for( int i = 0 ; e2( Pth[ i ] ) <= c ; i ++ ) {
		int expA = 0 , expC = 0 ;
		for( ; a%Pth[ i ] == 0 ; a /= Pth[ i ] , expA ++ ) ;
		for( ; c%Pth[ i ] == 0 ; c /= Pth[ i ] , expC ++ ) ;
		if( expC < expA ) {
			return -1 ;
		}
		if( expA != expC ) {
			b *= Pow( Pth[ i ] , expC ) ;
		}
	}
	if( c < a ) {
		return -1 ;
	}
	if( c != 1 ) {
		if( c != a ) {
			if( a != 1 ) return -1 ;
			b *= c ;
		}
	}
	return b ;
}

int main() {
	sieve( 1e4 ) ;
	int t ;
	cin >> t ;
	int a , c ;
	while( t -- ) {
		scanf( "%d %d" , &a , &c ) ;
		int b = fact( a , c ) ;
		if( b == -1 ) {
			printf( "NO SOLUTION\n" ) ;
		} else {
			printf( "%d\n" , b ) ;
		}
	}

	return 0 ;
}

