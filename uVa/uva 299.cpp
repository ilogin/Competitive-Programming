#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n;
	cin >> n;

	while (n--){
		int a, ans(0);
		cin >> a;
		int train[a];
		for (int i = 0; i < a; i++)
			cin >> train[i];

		int b = 1;

		while(b--){
			for (int i = 1; i < a; i++)
				if (train[i] < train[i-1]){
					swap (train[i], train[i-1]);
					ans++;
					b++;
				}
		}

		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}

	return 0;
}