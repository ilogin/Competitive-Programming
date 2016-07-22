#include <bits/stdc++.h>
using namespace std;

int main(){

	/*Mistake:
	-used a bool double array when checking if the glass > 1 is much more efficient

	Original:
	for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){

	Fixed:
	for (int i = 0; i < n; i++)
			for (int j = 0; j < n+1; j++){

	Counting amount of filled glasses and checking if glass above is filled should be one step instead of 2 different loops

	Instead of having a counter for time, set the first glass to have all the amount of wine; this
	way, the glass above will just have half of the glasses above


	*/

	int n, t;
	cin >> n >> t;
	
	double bot[n+1][n+1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			bot[i][j] = 0;

	bot[0][0] = t;

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (bot[i-1][j-1] >= 1){
				bot[i][j] += (bot[i-1][j-1] * 0.25);
				cout << "1 " << i << " " << j << endl;
			}
			if (bot[i-1][j] >= 1){
				bot[i][j] += (bot[i-1][j] * 0.25);
				cout << "2 " << i << " " << j << endl;
			}
			if (bot[i][j] >= 1) ans++;
		}


	cout << ans;
	system("PAUSE");

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