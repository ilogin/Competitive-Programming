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

	while(true){
		int n; cin >> n; if (n==0) break;
		int numbers[n]; for (int i = 0; i < n; i++) cin >> numbers[i];

		int ans = 0; int sum = 0;
		for (int i = 0; i < n; i++){
			sum += numbers[i];
			if (sum < 0) sum = 0;
			if (sum > ans) ans = sum;
		}

		if (ans > 0) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}

	return 0;
}