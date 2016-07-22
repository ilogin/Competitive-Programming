#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n;
	cin >> n;
	cin.ignore();

	while (n--){
		string a;
		getline(cin, a);

		if (a.length() == 0){
			cout << "Yes" << endl;
			continue;
		}

		if (a.length() % 2 == 1){
			cout << "No" << endl;
			continue;
		}

		stack <char> s;
		bool ans = true;

		for (int i = 0; i < a.length(); i++){
			char b = a[i];

			if (b == '(' || b == '[') s.push(b);
			else if (!s.empty() && b == ')' && s.top() == '(') s.pop();
			else if (!s.empty() && b == ']' && s.top() == '[') s.pop();
			else ans = false;
			}

		if (s.empty() && ans == true) cout << "Yes";
		else cout << "No";
		cout << endl;
	}


	return 0;
}