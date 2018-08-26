#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
vector<int> adj[ N ] ;
bool vis[ N ] ;

void dfs( int from ) {
	vis[ from ] = true ;
	for( int to : adj[ from ] ) {
		if( vis[ to ] ) continue ;
		dfs( to ) ;
	}
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
	dfs( 1 ) ;

   return 0 ;
}
