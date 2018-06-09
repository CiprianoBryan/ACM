#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int M = 1e6 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
inline int Ceil( int a , int b ) {
	return a/b + ( a%b != 0 ) ;
}

/************************************/
bool P[ N ] ;
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
int isPrime[ M ] ;

void solve( int n , int m ) {
	for( int i = 0 ; Pth[ i ]*Pth[ i ] <= m ; i ++ ) {
		int prime = Pth[ i ] ;
		int k = max( 2 , Ceil( n , prime ) ) ;
		for( int mult = prime*k ; mult <= m ; mult += prime ) {
			isPrime[ mult - n ] = false ;
		}
	}
	int cant = 0 ;
	for( int i = n ; i <= m ;i ++ ) {
		if( isPrime[ i - n ] && isPrime[ i - n + 2 ] ) {
			cant ++ ;
		}
	}
	printf( "%d\n" , cant ) ;
}

/************************************/

int main() {
	sieve( N ) ;
	int n , m ;
	cin >> n >> m ;
	solve( n , m ) ;

    return 0 ;
}
