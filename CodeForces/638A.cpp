#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	/*Original Mistake:
	Didn't consider the case when the car is already at the destination, i.e.

	bool ans = false;

	if (b == a) ans = true;
	if (c == a) ans = true;
	*/

	int n, a;
	cin >> n >> a;

	int b = n;
	int c = 1;
	int t = 1;
	bool ans = false;

	if (b == a) ans = true;
	if (c == a) ans = true;

	while (ans != true){
		b -= 2;
		c += 2;

		if (b == a) ans = true;
		if (c == a) ans = true;
		t++;
	}

	cout << t;

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