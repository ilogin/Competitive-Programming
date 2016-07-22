#include <bits/stdc++.h>
using namespace std;

int main(){

	/*Original mistake:

	//minimum
	for (int i = 0; i < n; i++)
		if (i % 6 == 0 || i % 7 == 0) min++;

	//maximum
	for (int i = 0; i < n; i++)
		if (i % 6 == 1 || i % 7 == 2) max++;

	Easiest solution is to use a counter, because ^^ does not work (days off are not necessarily "clean" multiples of 6 or 7)

	*/

	int n;
	cin >> n;

	//minimum
	int min = 0;
	int count = 1;
	for (int i = 1; i <= n; i++){
		if (count == 6 || count == 7) min++;
		count++;
		if (count == 8) count = 1;
	}

	count = 1;

	//maximum
	int max = 0;
	for (int i = 1; i <= n; i++){
		if (count == 1 || count == 2) max++;
		count++;
		if (count == 8) count = 1;
	}

	printf ("%d %d", min, max);

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