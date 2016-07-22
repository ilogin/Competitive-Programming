#include <bits/stdc++.h>
using namespace std;


int main(){

	int dollars;
	int cents;

	cin >> dollars;
	cin >> cents;

	stringstream ss;
	string dummy;

	ss << dollars;
	ss >> dummy;

	int length = dummy.length();
	int comma = length % 3;
	int use = length / 3;

	for (int i = 0; i < length; i++){
		if (i == 0) cout << '$';
		cout << dummy[i];
		if (i+1 == comma) cout << ',';
		if (i+1 > comma && (i+1-comma) % 3 == 0 && use != 0){
			cout << ',';
			use--;
		}
	}

	cout << '.';

	if (cents < 10) cout << '0' << cents;
	if (cents >= 10) cout << cents;

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