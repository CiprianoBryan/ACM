#include<bits/stdc++.h>
using namespace std ;

const int N = 100 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
vector<int> adj[ N ] ;
bool isAncestor[ N ][ N ] ; // primer numero es padre, segundo el hijo
int level[ N ] ;

void dfs( int cur , int fat , int niv ) {
	level[ cur ] = niv ;
    isAncestor[ fat ][ cur ] = true ;
	for( int nxt : adj[ cur ] ) {
		if( nxt == fat ) continue ;
		dfs( nxt , cur , niv + 1 ) ;
	}
}

int lca( int u , int v , int n ) {
	int root = 1 ; // el padre mas antiguo(mas arriba) es root
	dfs( root , 0 , 0 ) ;
    for( int a = 1 ; a <= n ; a ++ ) {
        for( int b = 1 ; b <= n ; b ++ ) {
            for( int c = 1 ; c <= n ; c ++ ) {
                if( isAncestor[ a ][ b ] && isAncestor[ b ][ c ] ) {
                    isAncestor[ a ][ c ] = true ;
                }
            }
        }
    }
    int lowestAncestor = root ;
    for( int ancestor = 1 ; ancestor <= n ; ancestor ++ ) {
        if( isAncestor[ ancestor ][ u ] && isAncestor[ ancestor ][ v ] && level[ lowestAncestor ] < level[ancestor] ) {
            lowestAncestor = ancestor;
        }
    }
    return lowestAncestor;
}

int main() {
	int n , m ;
	int u , v ;
	cin >> n >> m ; // numero de nodos(personas que conforman la familia) , numero de bordes o relaciones directas en la familia
	while( m -- ) {
		scanf( "%d %d" , &u , &v ) ; // par de nodos que tienen una relacion directa (padre/hijo) (no importa el orden)
		adj[ u ].push_back( v ) ;
		adj[ v ].push_back( u ) ;
	}
	int q ;
	cin >> q ;
	while( q -- ) {
		scanf( "%d %d" , &u , &v ) ;
		printf( "%d\n" , lca( u , v , n ) ) ;
	}

    return 0 ;
}
