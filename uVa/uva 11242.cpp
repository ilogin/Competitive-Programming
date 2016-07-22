#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;

int main(){

	int f(0);

	while(cin >> f, f != 0){
		int r; cin >> r;
		int front[f], rear[r];
		for (int i = 0; i < f; i++) cin >> front[i];
		for (int i = 0; i < r; i++) cin >> rear[i];

		vector <double> pos;

		for (int i = 0; i < f; i++)
			for (int j = 0; j < r; j++){
				double p = (double)rear[j]/front[i];
				pos.pb(p);
			}

		sort(pos.begin(), pos.end());
		double ans = 0;

		for(int i = 0; i < pos.size()-1; i++){
			double a = pos[i+1]/pos[i];
			ans = max(ans, a);
		}

		printf("%.2lf\n",ans);
	}

	return 0;
}