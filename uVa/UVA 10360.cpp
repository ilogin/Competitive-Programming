#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;

int main(){

	int t; cin >> t; while(t--){
		int d; cin >> d; int n; cin >> n;
		int killed[1025][1025] = {0};
		for (int i = 0; i < n; i++){
			int a, b, c; cin >> a >> b >> c;
			for (int j = a-d; j <= a+d; j++)
				for (int k = b-d; k <= b+d; k++)
					if (j >= 0 && k >= 0 && j <= 1024 && k <= 1024) killed[j][k] += c;
		}

		int left, right, ans(0);

		for (int i = 0; i <= 1024; i++)
			for (int j = 0; j <= 1024; j++)
				if (killed[i][j] > ans){
					left = i;
					right = j;
					ans = killed[i][j];
				}

		printf("%d %d %d\n", left, right, ans);
	}

	return 0;
}
