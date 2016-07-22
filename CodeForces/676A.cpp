#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int arr[n];
	int ma, mi;

	for (int i = 0; i < n; i++){
		cin >> arr[i];
		if (arr[i] == 1) mi = i;
		if (arr[i] == n) ma = i;	 
	}

	mi++;
	ma++;

	int d1 = ma-1;
	int d2 = mi-1;
	int d3 = n-mi;
	int d4 = n-ma;

	/*Original Mistake:
	int d1 = ma;
	int d2 = mi;

	3
	2 1 3
	
	Swap to: 1 2 3

	Output: 3
	Expected: 2
	*/

	cout << max(max(d1, d2), max(d3, d4));

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