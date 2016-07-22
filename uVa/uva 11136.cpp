#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n;
	cin >> n;

	while (n != 0){
		multiset <int> bills;
		ll ans = 0;

		for (int i = 0; i < n; i++){
			int a;
			cin >> a;

			for (int j = 0; j < a; j++){
				int b;
				cin >> b;
				bills.insert(b);
			}

			ans += *bills.rbegin() - *bills.begin();
			bills.erase(bills.begin());
			bills.erase( bills.find(*bills.rbegin()) );
		}

		cout << ans << endl;
		cin >> n;
	}


	return 0;
}