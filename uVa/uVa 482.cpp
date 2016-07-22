#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	int b;
	cin >> b;

	while (b--){
		string ex;
		getline(cin, ex);
		getline(cin, ex);
		getline(cin, ex);

		vector <int> arr;
		for (int i = 0; i < ex.length(); i+= 2){
			int a;
			stringstream ss;
			ss << ex[i];
			ss >> a;
			arr.push_back(a);
		}

		int n = arr.size();

		float ans[n];
		for (int i = 0; i < n; i++)
			cin >> ans[i];

		for (int i = 1; i <= n; i++)
			for (int j = 0; j < n; j++)
				if (arr[j] == i) cout << ans[j] << endl;

		cout << endl;
	}
	
	return 0;
}