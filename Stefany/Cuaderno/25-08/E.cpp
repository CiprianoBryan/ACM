#include <bits/stdc++.h>
using namespace std ;

const int N = 10 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
vector<int> adj[ N ] ;
int dist[ N ] ;

void BFS( int node , int n ) {
	for( int i = 1 ; i <= n ; i ++ ) {
		dist[ i ] = INF ;
	}
	queue<int> q ;
	q.push( node ) ;
	dist[ node ] = 0 ;
	while( !q.empty() ) {
		int A = q.front() ;
		q.pop() ;
		for( int B : adj[ A ] ) {
			if( dist[ B ] > dist[ A ] + 1 ) {
				dist[ B ] = dist[ A ] + 1 ;
				q.push( B ) ;
			}
		}
	}
}

int main() {
	// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
	int t ;
	cin >> t ;
	int n , m ;
	int u , v ;
	while( t -- ) {
		cin >> n >> m ;
		for( int i = 1 ; i <= n ; i ++ ) {
			adj[ i ].clear() ;
		}
		while( m -- ) {
			cin >> u >> v ;
			adj[ u ].push_back( v ) ;
			adj[ v ].push_back( u ) ;
		}
		BFS( 1 , n ) ;
		cout << dist[ n ] << endl ;
	}

   return 0 ;
}

