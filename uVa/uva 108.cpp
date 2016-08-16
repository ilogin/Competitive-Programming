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

int main(){

	int n; cin >> n; int DP[n][n];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
		cin >> DP[i][j];
		if (i > 0) DP[i][j] += DP[i-1][j];
		if (j > 0) DP[i][j] += DP[i][j-1];
		if (i > 0 && j > 0) DP[i][j] -= DP[i-1][j-1];
	}

	int ans = 0;

	for (int a = 0; a < n; a++) for (int b = 0; b < n; b++)
		for (int c = a; c < n; c++) for (int d = b; d < n; d++){
		int sum = DP[c][d];
		if (a > 0) sum -= DP[a-1][d];
		if (b > 0) sum -= DP[c][b-1];
		if (a > 0 && b > 0) sum += DP[a-1][b-1];
		if (sum > ans) ans = sum;
	}

	printf("%d\n", ans);

	return 0;
}