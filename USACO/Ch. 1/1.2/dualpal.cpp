#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

int n, s;

string new_base(int number, int base){
	stringstream ss;
	string ans;
	while (number > 0){
		ss << number % base;
		number /= base;
	}
	ss >> ans;
	reverse(ans.begin(), ans.end());
	return ans;
}

/*
ID: 1107451
TASK: dualpal
LANG: C++
*/

int main(){

	ofstream fout ("dualpal.out");
	ifstream fin ("dualpal.in");

	fin >> n >> s;

	while(n>0){
		s++;
		bool this_one = false; int count = 0;
		for(int i = 2; i <= 10; i++){
			string check = new_base(s, i);
			if (check == string(check.rbegin(), check.rend())) count++;
			if (count >= 2){
				this_one = true;
				continue;
			}
		}
		if (this_one){
			fout << s << endl;
			n--;
		}
	}

}