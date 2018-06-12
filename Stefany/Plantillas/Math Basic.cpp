/************************************/
bool isPrime( long long num ) { // O( sqrt( num )/log(num) )
	if( num <= M ) return P[ num ] ; // habiendo construido los booleanos primos de 1 a M
	for( int i = 0 ; e2( Pth[ i ] ) <= num ; i ++ ) {
		if( num%Pth[ i ] == 0 ) {
			return false ;
		}
	}
	return true ;
}

/************************************/
bool P[ N ] ;
vector<int> Pth ;

void sieve( int n ) { // O( N*loglogN )
	for( int i = 2 ; i <= n ; i ++ ) {
		P[ i ] = true ;
	}
	for( int num = 2 ; num <= n ; num ++ ) {
		if( !P[ num ] ) continue ;
		Pth.push_back( num ) ;
		for( int mult = 2*num ; mult <= n ; mult += num ) {
			P[ mult ] = false ;
		}
	}
}

/************************************/
int ddo[ N ] ;

void sieve( int n ) { // O( N )
	for( int i = 4 ; i <= n ; i += 2 ) {
		ddo[ i ] = 2 ;
	}
	for( int num = 3 ; num*num <= n ; num += 2 ) {
		if( ddo[ num ] ) continue ;
		for( int dor = num*num ; dor <= n ; dor += 2*num ) {
			ddo[ dor ] = num ;
		}
	}
}

/************************************/