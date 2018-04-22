#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = INT_MAX ;

/************************************/
inline int Ceil( int a , int b ) {
	return a/b + ( a%b != 0 ) ;
}

inline long long e2( int x ) {
	return 1LL*x*x ;
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

int main() {
	sieve( N + 1 ) ;
	int l , u ;
    while( scanf( "%d %d" , &l , &u ) == 2 ) {
    	set<int> notPrime ;
    	for( int i = 0 ; e2( Pth[ i ] ) <= u ; i ++ ) {
    		for( int k = max( 2 , Ceil( l , Pth[ i ] ) ) ; k <= u/Pth[ i ] ; k ++ ) {
    			notPrime.insert( Pth[ i ]*k ) ;
			}
		}
		vector<int> prime ;
		for( long long num = max( 2 , l ) ; num <= u ; num ++ ) {
			if( !notPrime.count( num ) ) {
				prime.push_back( num ) ;
			}
		}
		if( prime.size() <= 1 ) {
			printf( "There are no adjacent primes.\n" ) ;
			continue ;
		}
		int minD = INF , maxD = 0 ;
		for( int i = 1 ; i < prime.size() ; i ++ ) {
			minD = min( minD , prime[ i ] - prime[ i - 1 ] ) ;
			maxD = max( maxD , prime[ i ] - prime[ i - 1 ] ) ;
		}
		for( int i = 1 ; prime.size() ; i ++ ) {
			if( prime[ i ] - prime[ i - 1 ] == minD ) {
				printf( "%d,%d are closest, " , prime[ i - 1 ] , prime[ i ] ) ;
				break ;
			}
		}
		for( int i = 1 ; prime.size() ; i ++ ) {
			if( prime[ i ] - prime[ i - 1 ] == maxD ) {
				printf( "%d,%d are most distant.\n" , prime[ i - 1 ] , prime[ i ] ) ;
				break ;
			}
		}
	}

    return 0 ;
}
