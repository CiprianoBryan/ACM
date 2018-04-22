#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline int add( int a , int b ) {
	return ( a + b )%INF ;
}

inline int mult( int a , int b ) {
	return ( 1LL*a*b )%INF ;
}

/************************************/
int ddo[ N ] ;

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
int Exp[ N ] ;

void fact( int num , int m ) {
	while( ddo[ num ] ) {
		int e = 0 ;
		int div = ddo[ num ] ;
		while( num%div == 0 ) {
			num /= div ;
			e ++ ;
		}
		Exp[ div ] = add( Exp[ div ] , mult( e , m ) ) ;
	}
	if( num != 1 ) {
		Exp[ num ] = add( Exp[ num ] , m ) ;
	}
}

/************************************/
int fib[ N ] ;

int main() {
	sieve( N - 1 ) ;
	int n ;
	cin >> n ;
	fib[ 0 ] = fib[ 1 ] = 1 ;
	for( int i = 2 ; i < n ; i ++ ) {
		fib[ i ] = add( fib[ i - 1 ] , fib[ i - 2 ] ) ;
	}
	for( int i = 0 ; i < n ; i ++ ) {
		fact( n - i , fib[ i ] ) ;
	}
	int prod = 1 ;
	for( int i = 2 ; i <= n ; i ++ ) {
		prod = mult( prod , Exp[ i ] + 1 ) ;
	}
	cout << prod ;

	return 0 ;
}

