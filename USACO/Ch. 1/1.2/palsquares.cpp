#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 1107451
TASK: palsquare
LANG: C++
*/
int b;

string new_base(int a){
	stringstream ss;
	string ans;
	while (a > 0){
		int check = a % b;
		if (check < 10)ss << a % b;
		else if (check >= 10){
			char c = 'A'+check-10;
			ss << c;
		}
		a /= b;
	}
	ss >> ans;
	reverse(ans.begin(), ans.end());
	return ans;
}
/*
bool palindrome(string a){
	loop(i, a.size()/2)
		if (a[i] != a[a.size()-i]) return false;
	return true;
}*/

int main(){

	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");

	fin >> b;

	for (int i = 1; i <= 300; i++){
		string Andrew = new_base(i); string Bryan = new_base(i*i);
		if (Bryan == string(Bryan.rbegin(), Bryan.rend()))
			fout << Andrew << " " << Bryan << endl;
	}
}