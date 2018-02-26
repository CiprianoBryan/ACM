#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> Pair ;

const int N = 1e4 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
Pair a[ N ] ;
int day[ N ] ;

int main() {
	int n , l ;
	while( cin >> n >> l ) {
		for( int i = 0 ; i < n ; i ++ ) {
			scanf( "%d %d" , &a[ i ].first , &a[ i ].second ) ;
		}
		sort( a , a + n , greater<Pair>() ) ;
		memset( day , 0 , sizeof day ) ;
		int sum = 0 ;
		for( int i = 0 ; i < n ; i ++ ) {
			for( int j = a[ i ].second ; j >= 0 ; j -- ) {
				if( day[ j ] < l ) {
					sum += a[ i ].first ;
					day[ j ] ++ ;
					break ;
				}
			}
		}
		printf( "%d\n" , sum ) ;
	}

	return 0 ;
}