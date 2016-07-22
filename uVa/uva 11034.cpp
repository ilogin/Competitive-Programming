#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int c;
	cin >> c;

	while(c--){
		int l, m;
		queue <int> left, right;
		cin >> l >> m;
		l *= 100;

		while (m--){
			int a;
			string b;
			cin >> a >> b;
			if (b == "right") right.push(a);
			else left.push(a);
		}

		int ans = 0;
		while (! (left.empty() && right.empty())){
			int a = 0;

			if (left.empty()) ans++;

			while (!left.empty()){
				a += left.front();
				left.pop();

				if (a + left.front() > l || left.empty()){
					ans++;
					a = 0;
					break;
				}
			}

			if (left.empty() && right.empty()) break;

			if (right.empty()) ans++;

			while (!right.empty()){
				a += right.front();
				right.pop();

				if (a + right.front() > l || right.empty()){
					ans++;
					a = 0;
					break;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}