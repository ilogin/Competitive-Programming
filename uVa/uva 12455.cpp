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

	int t; cin >> t; while(t--){
		int need, have; cin >> need >> have;
		int bars[have]; for (int i = 0; i < have; i++) cin >> bars[i];

		bool ans = false;
		for (int i = 0; i < (1 << have); i++){
			int sum = 0;
			for (int j = 0; j < have; j++)
				if (i & (1 << j)) sum += bars[j];
			if (sum == need) ans = true;
		}

		if (ans) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}