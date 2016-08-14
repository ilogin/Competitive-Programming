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
int n, t, numbers[20];
vector<int>ans;
map<vector<int>, bool>check;

void solve(int pos, int sum, vector<int>ans){

	if (sum == t){
		if (check[ans] == true) return;
		check[ans] = true;
		for (int i = 0; i < ans.size()-1; i++) printf("%d+", ans[i]);
		printf("%d\n", ans[ans.size()-1]); return; 
	}

	if (pos == n || sum > t) return;
	for (int i = pos; i < n; i++){
		ans.push_back(numbers[i]);
		solve(i+1, sum + numbers[i], ans);
		ans.pop_back();
	}

}


int main(){


	while (true){
		scanf("%d %d", &t, &n); if (n == 0 && t == 0) break;

		for (int i = 0; i < n; i++) cin >> numbers[i];
		check.clear(); printf("Sums of %d:\n", t); solve(0, 0, ans);
		if (check.size() == 0) printf("NONE\n");
	}


	return 0;
}