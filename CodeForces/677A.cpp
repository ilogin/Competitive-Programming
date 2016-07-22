#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n, h;
	cin >> n >> h;

	int ans = 0;
	while (n--){
		int a;
		cin >> a;
		if (a > h) ans += 2;
		else ans++;
	}

	cout << ans;

	return 0;
}

/*
ID: 11074501
PROG: test
LANG: C++
*/

/*
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);	
*/