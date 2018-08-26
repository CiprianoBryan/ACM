#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

typedef pair<int,int> Pair ;
typedef vector<Pair> vPair ;

/************************************/
struct orden {
	bool operator() ( Pair p1 , Pair p2 ) {
		return p1.second > p2.second ;
	}
} ;

vPair adj[ N ] ;
int dist[ N ] ;

void dijkstra( int node ) {
	for( int i = 0 ; i < N ; i ++ ) {
		dist[ i ] = INF ;
	}
	dist[ node ] = 0 ;
	priority_queue<Pair,vPair,orden> q ;
	q.push( { node , 0 } ) ;
	while( !q.empty() ) {
		Pair t = q.top() ;
		q.pop() ;
		int a = t.first ;
		int da = t.second ;
		if( dist[ a ] < da ) continue ;
		for( Pair edge : adj[ a ] ) {
			int b = edge.first ;
			int cost = edge.second ;
			if( dist[ b ] > dist[ a ] + cost ) {
				dist[ b ] = dist[ a ] + cost ;
				q.push( { b , dist[ b ] } ) ;
			}
		}
	}
}

/************************************/

int main() {
	int n , m ;
	cin >> n >> m ;
	int u , v , w ;
	while( m -- ) {
		scanf( "%d %d %d" , &u , &v , &w ) ;
		adj[ u ].push_back( { v , w } ) ;
		adj[ v ].push_back( { u , w } ) ;
	}
	dijkstra( 1 ) ;
	cout << dist[ n ] ;

   return 0 ;
}

