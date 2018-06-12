#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/************************************/

bool used[2004][2004];
int memo[2004][2004];

string a, b;

int dp(int posA, int posB){
	if(posA == a.size() && posB == b.size()){
		return 0;
	}
	if(used[posA][posB]) return memo[posA][posB];
	used[posA][posB] = true;
	int &ans = memo[posA][posB] = INF;
	if( posA < a.size() ) ans = min(ans, 1 + dp(posA + 1, posB));
	if( posB < b.size() ) ans = min(ans, 1 + dp(posA, posB + 1));
	if( posB < b.size() && posA < a.size()){
		ans = min(ans, 1 + dp(posA + 1, posB + 1));
		if( a[ posA ] == b[ posB ] ) {
			ans = min( ans , dp(posA + 1, posB + 1) );
		}
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	for(int nroT = 0; nroT < t; nroT++){
		cin  >> a >> b;
		for(int i = 0; i < a.size(); i++){
			for(int j = 0; j < b.size(); j++){
				used[i][j] = false;
			}
		}
		cout << dp(0, 0) << endl;
	}
    return 0 ;
}
