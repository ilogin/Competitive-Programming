#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
int dummy[100]; int n; int Delton[100];

/*
ID: 1107451
TASK: crypt1
LANG: C++
*/

bool test(){
	stringstream aa, bb, cc;
	string first, second, third;
	aa << ((100*dummy[0] + 10*dummy[1] + dummy[2])*dummy[3]);
	bb << ((100*dummy[0] + 10*dummy[1] + dummy[2])*dummy[4]);
	cc << ((100*dummy[0] + 10*dummy[1] + dummy[2])*((10*dummy[4]) + dummy[3]));
	aa >> first;
	bb >> second;
	cc >> third;

	if (first.size() != 3 || second.size() != 3 || third.size() != 4) return false;
	loop(i, 3){
		bool Andrew, Bryan; Andrew = false; Bryan = false;
		char c = first[i]; char d = second[i];
		int cc = c - '0'; char dd = d - '0';
		loop (j, n){
			if (Delton[j] == cc) Andrew = true;
			if (Delton[j] == dd) Bryan = true;
		}
		if (Andrew == false || Bryan == false) return false;
	}
	loop(i, 4){
		bool Cory = false;
		char c = third[i]; int cc = c - '0';
		loop(j, n){
			if (Delton[j] == cc) Cory = true;
		}
		if (Cory != true) return false;
	}
	return true;
}

int main(){
	ofstream fout ("crypt1.out");
	ifstream fin ("crypt1.in");

	fin >> n;
	loop(i, n) fin >> Delton[i];
	int ans = 0;

	loop(a, n){
		dummy[0] = Delton[a];
		loop(b, n){
			dummy[1] = Delton[b];
			loop(c, n){
				dummy[2] = Delton[c];
				loop(d, n){
					dummy[3] = Delton[d];
					loop(e, n){
						dummy[4] = Delton[e];
						if(test())
							ans++;
					}
				}
			}
		}
	}
	fout << ans << endl;

}