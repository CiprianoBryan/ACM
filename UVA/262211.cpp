#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 0 ;
const int logN = log2( N ) + 2 ;
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
		int div = ddo[ num ] ;
		while( num%div == 0 ) {
			num /= div ;
			sum += div ;
		}
	}
	if( num != 1 ) {
		sum += num ;
	}
	return sum ;
}

/************************************/
int sopf[ N + 1 ] ;
int lsopf[ N + 1 ] ;

void init() {
	for( int i = 2 ; i <= N ; i ++ ) {
		sopf[ i ] = fact( i ) ;
		lsopf[ i ] = 1 ;
		for( int num = i ; num != sopf[ num ] ; num = sopf[ num ] ) {
			lsopf[ i ] ++ ;
		}
	}
}

/************************************/
int st[ N + 1 ][ logN ] ;

void buildST( int n ) {
	for( int i = 1 ; i <= n ; i ++ ) {
		st[ i ][ 0 ] = lsopf[ i ] ;
	}
	for( int loglen = 1 , len = 2 ; len <= n ; loglen ++ , len <<= 1 ) {
		for( int i = 1 ; i + len - 1 <= n ; i ++ ) {
			st[ i ][ loglen ] = max( st[ i ][ loglen - 1 ] , st[ i + len/2 ][ loglen - 1 ] ) ;
		}
	}
}

int query( int l , int r ) {
	if( l > r ) swap( l , r ) ;
	int loglen = log2( r - l + 1 ) ;
	int len = 1 << loglen ;
	return max( st[ l ][ loglen ] , st[ r - len + 1 ][ loglen ] ) ;
}

/************************************/

int main() {
	sieve( N ) ;
	init() ;
	int t ;
	cin >> t ;
	int n , m ;
	buildST( N ) ;
	for( int i = 1 ; i <= t ; i ++ ) {
		scanf( "%d %d" , &n , &m ) ;
		printf( "Case #%d:\n%d\n" , i , query( n , m ) ) ;
	}

	return 0 ;
}

