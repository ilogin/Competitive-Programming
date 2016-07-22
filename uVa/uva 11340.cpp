#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n;
	cin >> n;

	while (n--){
		int k;
		cin >> k;
		map <char, int> c;

		while(k--){
			char a;
			int b;
			cin >> a >> b;
			c[a] = b;
		}

		int m;
		cin >> m;
		m++;
		double ans = 0;

		while(m--){
			string a;
			getline(cin, a);

			for (int i = 0; i < a.length(); i++){
				char b = a[i];
				ans += c[b];
			}
		}

		if (ans == 0) cout << "0.00$" << endl;
		else cout << ans/100 << '$' << endl;
	}

	return 0;
}