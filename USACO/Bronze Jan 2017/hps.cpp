#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
vii trials;

int run(int hoof, int paper, int scissors){
	int count = 0;
	TRvii(trials, it){
		if (it->first != it->second){
			if (it->first == hoof && it->second == scissors) count++;
			if (it->first == paper && it->second == hoof) count++;
			if (it->first == scissors && it->second == paper) count++;
		}
	}
	return count;
}

/*
ID: 1107451
TASK: dualpal
LANG: C++
*/

int main(){

	ofstream fout ("hps.out");
	ifstream fin ("hps.in");

	//1: 1 = hoof, 2 = paper, 3 = scissors
	//2: 1 = hoof, 2 = scissors, 3 = paper
	//3: 1 = paper, 2 = hoof, 3 = scissors
	//4: 1 = paper, 2 = scissors, 3 = hoof
	//5: 1= scissors, 2 = hoof, 3 = paper
	//6: 1 = scissors, 2 = paper, 3 = hoof

	int n; fin >> n; while(n--){
		int a, b; fin >> a >> b;
		trials.push_back(make_pair(a, b));
	}
	int max = 0;
	int a = run(1, 2, 3); if (a > max) max = a;
	a = run(1, 3, 2); if (a > max) max = a;
	a = run(2, 1, 3); if (a > max) max = a;
	a = run(2, 3, 1); if (a > max) max = a;
	a = run(3, 2, 1); if (a > max) max = a;
	a = run(3, 1, 2); if (a > max) max = a;
	fout << max << endl;

}