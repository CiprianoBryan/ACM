#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
vector<int> adj[ N ] ;
bool vis[ N ] ;

void BFS( int node ) {
	queue<int> q ;
	q.push( node ) ;
	while( !q.empty() ) {
		int A = q.front() ;
		q.pop() ;
		vis[ A ] = true ;
		for( int B : adj[ A ] ) {
			if( vis[ B ] ) continue ;
			q.push( B ) ;
		}
	}
}

int main() {
	int n , m ;
	cin >> n >> m ;
	int x , y ;
	while( m -- ) {
		cin >> x >> y ;
		adj[ x ].push_back( y ) ;
		adj[ y ].push_back( x ) ;
	}
	BFS( 1 ) ;

   return 0 ;
}

