#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline int add( int a , int b , int mod ) {
	return ( a + b )%mod ;
}

inline int mult( int a , int b , int mod ) {
	return ( 1LL*a*b )%mod ;
}

/************************************/
int Pow( int b , int e , int mod ) {
	int prod = 1 ;
	for( ; e != 0 ; e >>= 1 ) {
		if( e&1 ) prod = mult( prod , b , mod ) ;
		b = mult( b , b , mod ) ;
	}
	return prod ;
}

int phi[ 40 ] ;

int inverseMod( int num , int mod ) {
	return Pow( num , phi[ mod ] - 1 , mod ) ;
}

/************************************/
int m[ 3 ] = { 23 , 28 , 33 } ;

int chineseRemainder( int n , int *x ) {
	long long M = 1 ;
	for( int i = 0 ; i < n ; i ++ ) {
		x[ i ] %= m[ i ] ;
		M *= m[ i ] ;
	}
	int ans = 0 ;
	for( int i = 0 ; i < n ; i ++ ) {
		long long M_ = M/m[ i ] ;
		ans = add( ans , mult( x[ i ] , mult( inverseMod( M_ , m[ i ] ) , M_ , M ) , M ) , M ) ;
	}
	return ans ;
}

/************************************/

int main() {
	phi[ 23 ] = 22 ;
	phi[ 28 ] = 12 ;
	phi[ 33 ] = 20 ;
	int p , e , i , d , nroT = 1 ;
	while( scanf( "%d %d %d %d" , &p , &e , &i , &d ) == 4 ) {
		if( p == -1 ) break ;
		int x[ 3 ] = { p , e , i } ;
		int ans = chineseRemainder( 3 , x ) ;
		while( ans <= d ) ans += m[ 0 ]*m[ 1 ]*m[ 2 ] ;
		printf( "Case %d: the next triple peak occurs in %d days.\n" , nroT ++ , ans - d ) ;
	}

	return 0 ;
}

