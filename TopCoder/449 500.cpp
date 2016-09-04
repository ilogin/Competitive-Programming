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

	int n; 
	n = 777;
	int memo[n+1];
	for (int i = 1; i <= n; i++){
		if (i % 2 == 1) memo[i] = i;
		else memo[i] = memo[i/2];
	}

	int sum = 0; for (int i = 1; i <= n; i++) sum += memo[i];

	cout << sum;

	return 0;
}