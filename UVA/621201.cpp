#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/

int main() {
	int n , m ;
	while( scanf( "%d %d" , &n , &m ) == 2 ) {
		long long ans = 1 ;
		for( int i = n - m + 1 ; i <= n ; i ++ ) {
			ans *= i ;
			for( ; ans%10 == 0 ; ans /= 10 ) ;
			ans %= 100000000000LL ;
		}
		printf( "%d\n" , ans%10 ) ;
	}

	return 0 ;
}

