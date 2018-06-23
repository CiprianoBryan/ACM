#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ; // maxima cantidad de nodos
const int logN = log2( N ) + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
vector<int> adj[ N ] ;
int depth[ N ] ;
int st[ N ][ logN ] ;

void dfs( int cur , int fat , int niv ) {
	depth[ cur ] = niv ;
	st[ cur ][ 0 ] = fat ;
	for( int nxt : adj[ cur ] ) {
		if( nxt == fat ) continue ;
		dfs( nxt , cur , niv + 1 ) ;
	}
}

void buildST( int n ) {
    int root = 1 ; // el padre mas antiguo(mas arriba) es root
	dfs( root , 0 , 0 ) ;
	for( int loglen = 1 , len = 2 ; len <= n ; loglen ++ , len <<= 1 ) {
		for( int u = 1 ; u <= n ; u ++ ) {
			if( !st[ u ][ loglen - 1 ] ) continue ;
			int v = st[ u ][ loglen - 1 ] ;
			st[ u ][ loglen ] = st[ v ][ loglen - 1 ] ;
		}
	}
}

int lca( int u , int v ) {
	if( depth[ u ] < depth[ v ] ) swap( u , v ) ;
	int lim = log2( depth[ u ] ) + 1 ;
	int len = 1 << lim ;
	for( int loglen = lim ; loglen >= 0 ; loglen -- , len >>= 1 ) {
		if( depth[ u ] - len >= depth[ v ] ) {
			u = st[ u ][ loglen ] ;
		}
	}
	if( u == v ) return u ;
	for( int loglen = lim ; loglen >= 0 ; loglen -- ) {
		if( !st[ u ][ loglen ] ) continue ;
		if( st[ u ][ loglen ] != st[ v ][ loglen ] ) {
			u = st[ u ][ loglen ] ;
			v = st[ v ][ loglen ] ;
		}
	}
	return st[ u ][ 0 ] ;
}

/************************************/

int main() {
	int n , m ;
	int u , v ;
	cin >> n >> m ; // numero de nodos(personas que conforman la familia) , numero de bordes o relaciones directas en la familia
	while( m -- ) {
		scanf( "%d %d" , &u , &v ) ; // par de nodos que tienen una relacion directa (padre/hijo) (no importa el orden)
		adj[ u ].push_back( v ) ;
		adj[ v ].push_back( u ) ;
	}
	buildST( n ) ;
	int q ;
	cin >> q ;
	while( q -- ) {
		scanf( "%d %d" , &u , &v ) ;
		printf( "%d\n" , lca( u , v ) ) ;
	}
	
	return 0 ;
}