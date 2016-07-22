#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	char c;
	char ans[50];
	int a = -1;

	while (cin.get(c)){

		a++;
		ans[a] = c;

		if (c == ' ' || c == '\n'){
			for (int i = a-1; i >= 0; i--) cout << ans[i];
			if (c == ' ') cout << ' ';
			if (c == '\n') cout << '\n';
			a = -1;
		}
	}

	return 0;
}