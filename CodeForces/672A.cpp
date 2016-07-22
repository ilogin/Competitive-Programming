#include <bits/stdc++.h>
using namespace std;

int main(){

	/*Original Mistake:

	ss << i;
	ex += ss.str();

	Stringstream acts as a stream buffer, so the addition of an integer
	accumulates in the stream buffer. The code instead should be

	ss << i;
	ex = ss.str();

	Because we don't want the stream buffer to repeat itself, only to add
	integers at the end.

	*/

	int n;
	cin >> n;

	string ex;
	stringstream ss;
	for (int i = 1; i <= n; i++){
		ss << i;
		ex = ss.str();
	}

	cout << ex[n-1];

		
	return 0;
}