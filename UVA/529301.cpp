#include<bits/stdc++.h>
using namespace std ;

const int N = 1e7 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline long long e2( int x ) {
	return 1LL*x*x ;
}

/************************************/
bool P[ N + 1 ] ;
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
void fact( long long num ) {
	for( int i = 0 ; e2( Pth[ i ] ) <= num ; i ++ ) {
		if( num%Pth[ i ] != 0 ) continue ;
		int div = Pth[ i ] ;
		while( num%div == 0 ) {
			num /= div ;
			printf( "    %d\n" , div ) ;
		}
	}
	if( num != 1 ) {
		printf( "    %lld\n" , num ) ;
	}
	printf( "\n" ) ;
}

/************************************/

int main() {
	sieve( N ) ;
	long long num ;
	while( cin >> num ) {
		if( num < 0 ) break ;
		fact( num ) ;
	}

	return 0 ;
}

