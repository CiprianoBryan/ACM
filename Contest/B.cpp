#include<bits/stdc++.h>
using namespace std ;

const int N = 100 + 2 ;
const int INF = 1e9 + 7 ;

string nivel = "0111222333344";

/************************************/
vector<int> adj[ N ] ;
bool isAncestor[ N ][ N ] ; // primer numero es padre, segundo el hijo
int level[ N ] ;

void preprocess( int n ) {//HALLAR ANCESTROS DE TODOS LOS USUARIOS
	for( int a = 1 ; a <= n ; a ++ ) { //foreach de todos los usuarios
        for( int b = 1 ; b <= n ; b ++ ) { //foreach de todos los usuarios
            for( int c = 1 ; c <= n ; c ++ ) { //foreach de todos los usuarios
                if( isAncestor[ a ][ b ] && isAncestor[ b ][ c ] ) {
                    isAncestor[ a ][ c ] = true ;
                }
            }
        }
    }
}

vector<int> lca( vector<int> childs , int n ) {
    int nroChilds = childs.size();
    int lowestLevel = 0 ;
    vector<int> ancestors ;
    for( int ancestor = 1 ; ancestor <= n ; ancestor ++ ) {
    	bool isCommunAncestor = true ;
    	for( int i = 0 ; i < nroChilds ; i ++ ) {
    		int child = childs[ i ] ;
    		if( !isAncestor[ ancestor ][ child ] ) {
    			isCommunAncestor = false ;
    			break ;
    		}
    	}
    	if( isCommunAncestor ) {
        	if( lowestLevel < level[ancestor] ) {
        		ancestors.clear();
        		lowestLevel = level[ancestor];
        	}
        	if( lowestLevel == level[ancestor] ) {
        		ancestors.push_back(ancestor);
        	}
        }
    }
    return ancestors;
}

int main() {
	int n , m ;
	int u , v ;
	cin >> n >> m ; // numero de nodos(personas que conforman la familia) , numero de bordes o relaciones directas en la familia
	while( m -- ) {
		scanf( "%d %d" , &u , &v ) ; // par de nodos que tienen una relacion directa (padre/hijo) (EN ORDEN)
		isAncestor[u][v] = true ;
		adj[ u ].push_back( v ) ;
		adj[ v ].push_back( u ) ;
	}
	for( int i = 0 ; i < n ; i ++ ) {
		level[ i + 1 ] = nivel[i] - '0';
	}
	preprocess( n );
	int q , child, nroChilds;
	cin >> q ;
	while( q -- ) {
		cin >> nroChilds ;
		vector<int> childs;
		for( int i =0 ; i < nroChilds; i ++ ) {
			scanf( "%d" , &child );
			childs.push_back(child);
		}
		vector<int> ancestors = lca(childs, n);
		for( int i = 0 ; i < ancestors.size() ; i++ ) {
			printf( "%d " , ancestors[i] );
		}
		printf("\n");
	}

    return 0 ;
}
