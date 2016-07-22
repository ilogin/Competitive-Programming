#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	//memory error on test 13

	ll n, k;
	cin >> n >> k;

	ll a[n];
	stringstream ss;
	string ex;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ss << a[i];
		ex += ss.str();
	}

	cout << ex[k-1];

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