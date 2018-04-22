#include<bits/stdc++.h>
using namespace std ;

const int N = 1e4 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
char s[ N ] ;

int main() {
	int t , num ;
	cin >> t ;
	while( t -- ) {
		scanf( " %[^\n]s" , s ) ;
		stringstream out( s ) ;
		vector<int> nums ;
		while( out >> num ) {
			nums.push_back( num ) ;
		}
		int ans = 1 ;
		for( int i = 0 ; i < nums.size() ; i ++ ) {
			for( int j = i + 1 ; j < nums.size() ; j ++ ) {
				ans = max( ans , __gcd( nums[ i ] , nums[ j ] ) ) ;
			}
		}
		printf( "%d\n" , ans ) ;
	}

	return 0 ;
}

