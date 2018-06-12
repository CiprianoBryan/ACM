#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/

int v[ N ] ;
int t[ N ] ;
long long T[ N ] ;

int bs( int i , int n ) {
	int l = i , r = n ;
	while( l <= r ) {
		int me = ( l + r ) >> 1 ;
		if( T[ me ] - T[ l - 1 ] >= v[ i ] ) r = me - 1 ;
		else l = me + 1 ;
	}
	return l ;
}

int cantt[ N ] ;
long long ans[ N ] ;

int main() {
	int n ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &v[ i ] ) ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &t[ i ] ) ;
		T[ i ] = T[ i - 1 ] + t[ i ] ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		int r = bs( i , n ) ;
		if( T[ r ] - T[ i - 1 ] != v[ i ] ) {
			ans[ r ] += v[ i ] - ( T[ r - 1 ] - T[ i - 1 ] ) ;
			r -- ;
		}
		cantt[ i ] ++ ;
		cantt[ r + 1 ] -- ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		cantt[ i ] += cantt[ i - 1 ] ;
		ans[ i ] += 1LL*t[ i ]*cantt[ i ] ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		printf( "%lld " , ans[ i ] ) ;
	}

    return 0 ;
}
