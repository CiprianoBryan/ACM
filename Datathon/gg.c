#include<stdio.h>
#include<math.h>

void f( int n ) {
	int p = -1 ; // not exist
	int f = 0 ;
	for( int k = 1 ; k <= n ; k ++ ) {
		int b = 2*k + 1 , c = 2*k - 2*n ;
		int x = ( -b + sqrt( b*b - 4*c ) )/2 ;
		int l = k , r = k + x ;
		if( r*( r + 1 )/2 - ( l - 1 )*l/2 == n ) {
			f ++ ;
			if( p == -1 ) {
				p = l ;
			}
		}
	}
	printf( "f=%d y p=%d\n" , f , p ) ;
}

int main() {
	f( 33 ) ;

	return 0 ;
}
