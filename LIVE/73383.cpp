#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> Pair ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
multiset<Pair> q ;

int main() {
	int type ;
	int k , p ;
	while( cin >> type ) {
		if( type == 0 ) break ;
		if( type == 1 ) {
			scanf( "%d %d" , &k , &p ) ;
			q.insert( { p , k } ) ;
		}
		if( type == 2 ) {
			printf( "%d\n" , q.empty() ? 0 : q.rbegin()->second ) ;
			if( !q.empty() ) {
				q.erase( ( -- q.end() ) ) ;
			}
		}
		if( type == 3 ) {
			printf( "%d\n" , q.empty() ? 0 : q.begin()->second ) ;
			if( !q.empty() ) {
				q.erase( q.begin() ) ;
			}
		}
	}

	return 0 ;
}