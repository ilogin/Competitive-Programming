/*
ID: 1107501
TASK: milk2
LANG: C++
*/

#include <bits/stdc++.h>
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
ll coins[5] = {1, 5, 10, 25, 50}; ll change;
ll DP[5][30001];

ll ways(ll type, ll value){

	if (value == 0) return 1;
	if (type == 5 || value < 0) return 0;
 	if (DP[type][value] != -1) return DP[type][value];
	/*
	Before:

	for (int i = type; i < 6; i++){
		DP[type][value] = ways(type + 1, value) + ways(type, value - coins[type]);
	}

	*/

	return DP[type][value] = ways(type + 1, value) + ways(type, value - coins[type]);
}

int main(){

	memset(DP, -1, sizeof DP);
	while(scanf("%lld", &change) != EOF){
		ll ans = ways(0, change);
		if (ans == 1) printf("There are %lld way to produce %lld cents change.\n", ans, change);
		else printf("There are %lld ways to produce %lld cents change.\n", ans, change);
	}

	return 0;
}