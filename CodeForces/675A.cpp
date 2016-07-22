#include <bits/stdc++.h>
using namespace std;


int main(){

	/*Original Mistake:
	Didn't read that b is a positive integer
	Didn't consider the case when b < a and c > 0, which means that 1 -4 -5 is perfectly valid
	Didn't consider the case when b != a and c = 0, so 0 1 0 is not valid
	Didn't consider how large the number could be, so long long is more appropriate than integer
	*/

	int a, b, c;
	cin >> a >> b >> c;

	bool ans = false;

	while (ans == false){
		if (c == 0 && b != a) break;
		if (b < a && c >= 0) break;
		if (a > b && c >= 0) break;
		if (a == b) ans = true;
		a += c;
	}

	if (ans == false) cout << "NO";
	if (ans == true) cout << "YES";

}

/*Better Solutions:

	if (a == b || ((c != 0 && (b-a)% c == 0 && (b-a)/c >= 0)))
	cout << "YES";
	else cout << "NO";

	This concise solution satisfies all the requirements of the problem.
	It checks if the difference between two neighboring elements if equal to c:

		(b-a) % c ==0

	And also checks if there exists a positive integer i such that si = b:

		(b-a)/c >= 0

	It also considers the case when c is 0 by checking if a = b.

	This problem could be made even shorter using a ternary operator, which I saw an interesting case of:

	if (c == 0)
		cout << ((a == b) ? "YES" : "NO") << endl;
*/