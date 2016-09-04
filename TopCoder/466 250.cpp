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
int price, banknotes[4];
bool ans(false);

void solve(int current_sum, int pos){

	if (current_sum == price) ans = true;

	for (int i = 0; i < 4; i++){
		if (current_sum + banknotes[i] <= price)
			solve(current_sum + banknotes[i], pos + 1);
	}
}

int main(){

	cin >> price;
	for (int i = 0; i < 4; i++) cin >> banknotes[i];
	solve(0, 0);

	if (!ans) cout << "IMPOSSIBLE";
	else cout << "POSSIBLE";

	return 0;
}