#include <bits/stdc++.h>
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef set<int> si;

int main(){

	//This script outputs all products of distinct primes (e.g. 3 * 7 = 21, 2 * 5 = 10)

	int begin(2), end(43);

	//Record all primes between begin and end
	bool check[end]; memset(check, true, sizeof check);
	int num_primes = 0; vi primes;
	for (int i = 2; i <= end; i++)
		for (int j = 0; j <= end; j++){
			if (j % i == 0 && j != i) check[j] = false;
		}
	for (int i = begin; i <= end; i++) if (check[i] == true) primes.pb(i);

	//Output
	si products;
	forit(it1, primes) forit(it2, primes)
			if (it1 != it2 && *it1 * *it2 <= end) products.insert(*it1 * *it2);

	forit(it, products) printf("%d ", *it);

	return 0;
}