#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 1107451
TASK: sort3
LANG: C++
*/

int space[1001];

void swap(int a, int b){
	int c = space[a]; int d = space[b];
	space[a] = d; space[b] = c; return;
}

int main(){
	ofstream fout ("sort3.out");
	ifstream fin ("sort3.in");

	int n; fin >> n;
	memset(space, 0, sizeof space);
	int count_1 = 0; int count_2 = 0; int count_3 = 0;
	int ans = 0;

	loop(i, n){
		fin >> space[i];
		if (space[i] == 1) count_1++;
		if (space[i] == 2) count_2++;
		if (space[i] == 3) count_3++;
	}

	for (int i = count_1; i < n; i++)
		if (space[i] == 1){
			int dummy = 0;
			for(int j = 0; j < count_1; j++){
				if (space[j] != 1) dummy = j;
				if (space[j] == 2) break;
			}
			swap(i, dummy);
			ans++;
		}

	for (int i = count_1 + count_2; i < n; i++)
		if (space[i] == 2) ans++;

	fout << ans << endl;
}