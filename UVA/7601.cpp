#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
int gcd( int a , int b ) {
	if( b == 0 ) return a ;
	return gcd( b , a%b ) ;
}

bool isTrip[ N ] ;
int n , cant ;

void check( int x , int y , int z ) {
	for( int k = 1 ; k*z <= n ; k ++ ) {
		isTrip[ k*x ] = true ;
		isTrip[ k*y ] = true ;
		isTrip[ k*z ] = true ;
	}
	if( gcd( x , y ) == 1 ) {
		cant ++ ;
	}
}

int main() {
    while( scanf( "%d" , &n ) == 1 ) {
    	for( int i = 1 ; i <= n ; i ++ ) {
    		isTrip[ i ] = false ;
    	}
    	cant = 0 ;
    	for( int b = 1 ; b*b <= n ; b ++ ) {
    		for( int a = b + 1 ; a*a <= n ; a ++ ) {
    			if( a*a + b*b > n ) continue ;
    			check( a*a - b*b , 2*a*b , a*a + b*b ) ;
			}
		}
		int cant2 = 0 ;
		for( int p = 1 ; p <= n ; p ++ ) {
			if( !isTrip[ p ] ) {
				cant2 ++ ;
			}
		}
		printf( "%d %d\n" , cant , cant2 ) ;
	}

    return 0 ;
}
