	#include <bits/stdc++.h>
	#define ll long long
	using namespace std;

	int main(){

		int n = -1;

		while(n != 0){
			cin >> n;
			if (n == 0) break;

			while (true){
				int order[n];
				cin >> order[0];
				if (order[0] == 0) break;

				for (int i = 1; i < n; i++)
					cin >> order[i];

				stack <int> station;
				int a(1), b(0);

				while(true){
					station.push(a);

					while(!station.empty() && station.top() == order[b]){
						station.pop();
						b++;
					}

					if (a == n) break;
					a++;
				}

				if (station.empty()) cout << "Yes" << endl;
				else cout << "No" << endl;
			}

			cout << endl;
		}

		return 0;
	}