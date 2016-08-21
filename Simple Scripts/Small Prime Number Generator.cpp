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
	int num_primes = 0;
	for (int i = 2; i <= end; i++)
		for (int j = 0; j <= end; j++){
			if (j % i == 0 && j != i) check[j] = false;
		}

	vector<int>primes, products;
	for (int i = begin; i <= end; i++) if (check[i] == true) primes.pb(i);

	for (int i = 0; i < primes.size(); i++){
		int product = primes[i] * primes[i+1];
		if (product > end) break;
		else products.pb(product);
	}

	for (int i = 0; i < products.size(); i++) printf("%d ", products[i]);

	return 0;
}