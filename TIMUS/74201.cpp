#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
void gcdExt( int a , int &x , int b , int &y , int &g ) {
	if( b == 0 ) {
		g = a , x = 1 , y = 0 ;
		return ;
	}
	gcdExt( b , y , a%b , x , g ) ;
	y = y - ( a/b )*x ;
}


/************************************/

int main() {
	int t , n ;
	cin >> t ;
	int p , q ;
	while( t -- ) {
		scanf( "%d" , &n ) ;
		for( int i = 2 ; i*i <= n ; i ++ ) {
			if( n%i != 0 ) continue ;
			p = i , q = n/i ;
			break ;
		}
		int x1_ , x2_ , y_ , g ;
		gcdExt( p , x1_ , q , y_ , g ) ;
		gcdExt( q , x2_ , p , y_ , g ) ;
		int x1 = ( p*x1_ + n )%n , x2 = ( q*x2_ + n )%n ;
		if( x1 > x2 ) swap( x1 , x2 ) ;
		printf( "0 1 %d %d\n" , x1 , x2 ) ;
	}

	return 0 ;
}

