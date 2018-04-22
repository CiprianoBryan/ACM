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
void gcdExt( int a , int &x , int b , int &y , int &g ) {
	if( b == 0 ) {
		g = a , x = 1 , y = 0 ;
		return ;
	}
	gcdExt( b , y , a%b , x , g ) ;
	y = y - ( a/b )*x ;
}

int inverseMod( int num , int mod ) {
	int x , y , g ;
	gcdExt( num , x , mod , y , g );
	return ( x%mod + mod )%mod ;
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
