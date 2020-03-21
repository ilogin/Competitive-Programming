#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 1107451
TASK: barn1
LANG: C++
*/

int main(){
	ofstream fout ("barn1.out");
	ifstream fin ("barn1.in");

	int m, s, c; fin >> m >> s >> c;
	int stalls[c];

	loop(i, c) fin >> stalls[i];
	sort(stalls, stalls+c);
	int diff[c-1];
	loop(i, c-1) diff[i] = stalls[i+1] - stalls[i] - 1;
	sort(diff, diff + (c-1));

	int ans = stalls[c-1]-stalls[0] + 1;
	for (int i = 0; i < m-1; i++){
		if (i == c-1) break;
		ans -= diff[c-2-i];
	}
	fout << ans << endl;
}