#include<bits/stdc++.h>
using namespace std ;
typedef long long Long ;
typedef long double LongD ;

const int N = 5e3 + 2 ;
const Long INF = 2e18 + 7 ;
const LongD EPS = 1e-12 ;

/************************************/
Long k , d , t ;
LongD P , A ;

inline Long Ceil( Long a , Long b ) {
	return a/b + ( a%b != 0 ) ;
}

bool ok( LongD x ) {
	LongD nroK = Long(x/A) + min( LongD(k) , x - Long(x/A)*A )/k ;
	LongD nroP = P ? Long(x/A) + max( LongD(0) , x - Long(x/A)*A - k )/P : 0 ;
	return (k*nroK)/t + (P*nroP)/(2*t) + EPS >= 1 ;
}

LongD bs() {
	LongD l = 0 , r = INF ;
	for( int i = 0 ; i < 110 ; i ++ ) {
		LongD me = ( r + l )/2 ;
		if( ok( me ) ) r = me ;
		else l = me ;
	}
	return l ;
}

int main() {
	cout.precision(10);
	cin >> k >> d >> t ;
	P = k < d ? d - k : d*Ceil( k , d ) - k ;
	A = k + P ;
	cout << bs() ;

	return 0 ;
}