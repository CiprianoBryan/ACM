#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/

int main() {
	printf( "Escribir tipo de vehiculo:\n" ) ;
	char automovil[ 30 ] ;
	gets( automovil ) ;
	if( strcmp( automovil , "turismo" ) == 0 ) printf( "\npeaje = 500" ) ;
	else if( strcmp( automovil , "autobus" ) == 0 ) printf( "\npeaje = 3000" ) ;
	else if( strcmp( automovil , "motocicleta" ) == 0 ) printf( "\npeaje = 300" ) ;
	else printf( "\nvehiculo no autorizado" );

	return 0 ;
}

