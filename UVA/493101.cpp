#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline long long e2( int x ) {
	return 1LL*x*x ;
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
bool solve( int n , int m ) {
	for( int i = 0 ; e2( Pth[ i ] ) <= m ; i ++ ) {
		if( m%Pth[ i ] != 0 ) continue ;
		int div = Pth[ i ] ;
		int exp = 0 ;
		while( m%div == 0 ) {
			m /= div ;
			exp ++ ;
		}
		int expF = 0 ;
		int tmp = n ;
		while( tmp ) {
			expF += tmp/div ;
			tmp /= div ;
		}
		if( expF < exp ) {
			return false ;
		}
	}
	if( m != 1 ) {
		if( n < m ) {
			return false ;
		}
	}
	return true ;
}

int main() {
	sieve( N - 1 ) ;
	int n , m ;
	while( scanf( "%d %d" , &n , &m ) == 2 ) {
		if( solve( n , m ) ) {
			printf( "%d divides %d!\n" , m , n ) ;
		} else {
			printf( "%d does not divide %d!\n" , m , n ) ;
		}
	}

	return 0 ;
}
