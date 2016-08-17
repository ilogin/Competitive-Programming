/*
ID: 1107501
TASK: milk2
LANG: C++
*/

#include <bits/stdc++.h>
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){

	int begin, end;
	begin = 2; end = 43;

	bool check[end]; memset(check, 1, sizeof check);
	for (int i = 2; i <= end; i++)
		for (int j = 0; j <= end; j++){
			if (j % i == 0 && j != i) check[j] = false;
		}

	for (int i = begin; i <= end; i++) if (check[i] == true) printf("%d ", i);

	return 0;
}