#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
int sum[ N ] ;
int pos[ N ] ;
int a[ N ] ;

int main() {
	int c , n , num ;
	while( scanf( "%d %d" , &c , &n ) == 2 ) {
		if( c == 0 && n == 0 ) break ;
		for( int i = 1 ; i <= n ; i ++ ) {
			scanf( "%d" , &a[ i ] ) ;
			pos[ i ] = -1 ;
		}
		for( int i = 1 ; i <= n ; i ++ ) {
			sum[ i ] = ( sum[ i - 1 ] + a[ i ] )%c ;
			if( pos[ sum[ i ] ] != -1 ) {
				for( int j = pos[ sum[ i ] ] + 1 ; j <= i ; j ++ ) {
					printf( "%d"  , j ) ;
					if( i != j ) printf( " " ) ;
				}
				printf( "\n" ) ;
				break ;
			}
			pos[ sum[ i ] ] = i ;
		}
	}

	return 0 ;
}

