#include <bits/stdc++.h>
using namespace std;

int main(){

	/*Original Mistake:
	Didn't read the problem (the game lasts 90 minutes)

	if (min[i] - min[i-1] <= 15) ans = min[i] + 15;
	^^ The program should stop after this line, because he won't watch the next few minutes.

	if (min[0] > 15) then the answer should be 15, because he only turns off the TV if 15 consecutive minutes are boring.


	*/

	int n;
	cin >> n;

	int min[n];
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> min[i];
		if (min[0] > 15) break;
		if (min[i] - min[i-1] > 15) break;
		ans = min[i] + 15;
	}

	if (ans == 0) ans = 15;
	if (ans > 90) ans = 90;

	cout << ans;
		
	return 0;
}