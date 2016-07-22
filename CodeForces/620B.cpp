#include <bits/stdc++.h>
#define ll long long
using namespace std;

int check(int x){
	if (x == 0) return 6;
	if (x == 1) return 2;
	if (x == 2) return 5;
	if (x == 3) return 5;
	if (x == 4) return 4;
	if (x == 5) return 5;
	if (x == 6) return 6;
	if (x == 7) return 3;
	if (x == 8) return 7;
	if (x == 9) return 6;
}

int main(){

	ll a, b;
	cin >> a >> b;

	int ans = 0;
	for (ll i = a; i <= b; i++){
		ans += check(i % 10);
		for (ll j = 10; j <= i; j *= 10)
			ans += check((i / j) % 10);
	}

	cout << ans;

	return 0;
}