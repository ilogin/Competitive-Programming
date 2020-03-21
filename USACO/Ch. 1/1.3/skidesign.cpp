#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 11074501
TASK: skidesign
LANG: C++
*/

int main(){
	ofstream fout ("skidesign.out");
	ifstream fin ("skidesign.in");

	int n; fin >> n; int hills[n]; loop(i,n) fin >> hills[i];

	long long ans = 101000000;
	for (int i = 0; i <= 83; i++){
		long long cost = 0;
		loop(j, n){
			if (hills[j] > i + 17) cost += pow(hills[j] - i - 17, 2);
			if (hills[j] < i) cost += pow(i - hills[j], 2);
		}
		if (cost < ans) ans = cost;
	}

	fout << ans << endl;
}