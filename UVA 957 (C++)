#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;

int main(){

	int y, p; 

	while(scanf("%d %d", &y, &p) != EOF){
		vector<int>popes;
		for (int i = 0; i < p; i++){
			int a; cin >> a; popes.pb(a);
		}	

		int ans = 0;
		int begin = 0; int end = 0;
		forit(it1, popes){
			vector<int>::iterator it2 = upper_bound(popes.begin(), popes.end(), *it1 + y - 1);
			if (it2 - it1 > ans){
				ans = it2 - it1;
				begin = *it1;
				end = *(it2-1);
			}
		}

		printf("%d %d %d\n", ans, begin, end);

	}
	return 0;
}
