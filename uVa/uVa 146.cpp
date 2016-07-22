#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	string ex;
	getline(cin, ex);

	while (ex != "#"){
		int n = ex.length();
		char arr[n];

		for (int i = 0; i < n; i++)
			arr[i] = ex[i];

		if (next_permutation(arr, arr+n) == true){
			for (int i = 0; i < n; i++)
			cout << arr[i];
		}
		else cout << "No Successor";
		cout << endl;

		getline(cin, ex);
	}

	return 0;
}