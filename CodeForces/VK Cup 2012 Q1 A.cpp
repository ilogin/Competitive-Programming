#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= a[k-1] && a[i] > 0) ans++;

	/* Original Mistake: Forgot that arrays begin from 0:

	for (int i = 0; i < n; i++)
		if (a[i] >= a[k] && a[i] > 0) ans++;

	*/

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