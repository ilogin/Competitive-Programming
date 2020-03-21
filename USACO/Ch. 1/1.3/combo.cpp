#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 1107451
TASK: combo
LANG: C++
*/

int main(){ 
	ofstream fout ("combo.out");
	ifstream fin ("combo.in");

	int n, a, b, c, d, e, f;
	fin >> n >> a >> b >> c >> d >> e >> f;

	int dummy[101][101][101] = {0};
	int ans = 0;

	for (int i = a-2; i < a+3; i++){
		int back1 = i;
		if (i <= 0) back1 = n+i;
		if (i > n) back1 = i-n;
		for (int j = b-2; j < b+3; j++){
			int back2 = j;
			if (j <= 0) back2 = n+j;
			if (j > n) back2 = j-n;
			for (int k = c-2; k < c+3; k++){
				int back3 = k;
				if (k <= 0) back3 = n+k;
				if (k > n) back3 = k-n;
				if (dummy[back1][back2][back3] == 0){
					if (back1 > 0 && back1 <= n &&
						back2 > 0 && back2 <= n &&
						back3 > 0 && back3 <= n){
					ans++;
					dummy[back1][back2][back3] = 1;
				}
				}
			}
		}
	}

	for (int i = d-2; i < d+3; i++){
		int back1 = i;
		if (i <= 0) back1 = n+i;
		if (i > n) back1 = i-n;
		for (int j = e-2; j < e+3; j++){
			int back2 = j;
			if (j <= 0) back2 = n+j;
			if (j > n) back2 = j-n;
			for (int k = f-2; k < f+3; k++){
				int back3 = k;
				if (k <= 0) back3 = n+k;
				if (k > n) back3 = k-n;
				if (dummy[back1][back2][back3] == 0){
					if (back1 > 0 && back1 <= n &&
						back2 > 0 && back2 <= n &&
						back3 > 0 && back3 <= n){
					ans++;
					dummy[back1][back2][back3] = 1;
				}
				}
			}
		}
	}
	fout << ans << endl;
}