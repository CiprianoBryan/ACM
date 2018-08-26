#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
vector<int> adj[ N ] ;
bool vis[ N ] ;

bool dfs( int from , int goal ) {
	vis[ from ] = true ;
	if( from == goal ) return true ;
	for( int to : adj[ from ] ) {
		if( vis[ to ] ) continue ;
		if( dfs( to , goal ) ) return true ;
	}
	return false ;
}

/************************************/

int main() {
	int n , m ;
	cin >> n >> m ;
	int x , y ;
	while( m -- ) {
		cin >> x >> y ;
		adj[ x ].push_back( y ) ;
		adj[ y ].push_back( x ) ;
	}
	int Start , End ;
	while( cin >> Start >> End ) {
		for( int i = 0 ; i < n ; i ++ ) {
			vis[ i ] = false ;
		}
		if( dfs( Start , End ) ) {
			cout << "Si se llego a la meta teleton\n" ;
		} else {
			cout << "Nel prro\n" ;
		}
	}

   return 0 ;
}
