#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define CLR(V, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)
using namespace std ;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-8 ;

/************************************/
vector<int> adj[ N ] ;
bool vis[ N ] ;

void dfs( int from ) {
	vis[ from ] = true ;
	for( int to : adj[ from ] ) {
		if( vis[ to ] ) continue ;
		dfs( to ) ;
	}
}

/************************************/

int main() {
	

   return 0 ;
}

