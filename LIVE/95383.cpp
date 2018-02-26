#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/
pair<double,double> P[ N ] ;

inline double e2( double x ) {
	return x*x ;
}

double distance( double x1 , double y1 , double x2 , double y2 ) {
	return sqrt( e2( x1 - x2 ) + e2( y1 - y2 ) ) ;
}

int main() {
	int n ;
	double d , l ;
	while( cin >> l ) {
		cin >> d >> n ;
		for( int i = 0 ; i < n ; i ++ ) {
			cin >> P[ i ].first >> P[ i ].second ;
		}
		sort( P , P + n ) ;
		double Right = -1 ;
		int cant = 0 ;
		for( int i = 0 ; i < n ; i ++ ) {
			if( Right == -1 || ( distance( P[ i ].first , P[ i ].second , Right , 0 ) > d && Right < P[ i ].first ) ) {
				Right = P[ i ].first + sqrt( e2( d ) - e2( P[ i ].second ) ) ;
				cant ++ ;
				continue ;
			}
			if( distance( P[ i ].first , P[ i ].second , Right , 0 ) > d ) {
				Right = P[ i ].first + sqrt( e2( d ) - e2( P[ i ].second ) ) ;
			}
		}
		cout << cant << endl;
	}

	return 0 ;
}