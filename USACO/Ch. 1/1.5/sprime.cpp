#include <bits/stdc++.h>
using namespace std;
#define fa(i, a, b) for (int i = a; i < b; i++)
#define loop(i, b) for (int i = 0; i < b; i++)

/*
ID: 1107441
TASK: sprime
LANG: C++
*/

bool isprime(int num){
	while (num != 0){
		if (num == 1) return false;
		fa(i, 2, sqrt(num)) if (num % i == 0) return false;
		num /= 10;
	}
	return true;
}

int main(){
	ofstream fout ("sprime.out");
	ifstream fin ("sprime.in");

	int n; fin >> n;
	int first_row[4] = {2, 3, 5, 7};
	int next_row[4] = {1, 3, 7, 9};

	if (n == 1) loop (i, 4) fout << first_row[i] << endl;
	if (n == 2)
		loop(a, 4) loop(b, 4){
			int prime = 10*first_row[a] + next_row[b];
			if (isprime(prime)) fout << prime << endl;
		}
	if (n == 3)
		loop(a, 4) loop(b, 4) loop(c, 4){
			int prime = 100*first_row[a] + 10*next_row[b] + next_row[c];
			if (isprime(prime)) fout << prime << endl;
		}
	if (n == 4)
		loop(a, 4) loop(b, 4) loop(c, 4) loop(d, 4){
			int prime = 1000*first_row[a] + 100*next_row[b] + 10*next_row[c] + next_row[d];
			if (isprime(prime)) fout << prime << endl;
		}
	if (n == 5)
		loop(a, 4) loop(b, 4) loop(c, 4) loop(d, 4) loop(e, 4){
			int prime = 10000*first_row[a] + 1000*next_row[b] + 100*next_row[c] + 10*next_row[d] + next_row[e];
			if (isprime(prime)) fout << prime << endl;
		}
	if (n == 6)
		loop(a, 4) loop(b, 4) loop(c, 4) loop(d, 4) loop(e, 4) loop(f, 4){
			int prime = 100000*first_row[a] + 10000*next_row[b] + 1000*next_row[c] + 100*next_row[d] + 10*next_row[e] + next_row[f];
			if (isprime(prime)) fout << prime << endl;
		}
	if (n == 7)
		loop(a, 4) loop(b, 4) loop(c, 4) loop(d, 4) loop(e, 4) loop(f, 4) loop(g, 4){
			int prime = 1000000*first_row[a] + 100000*next_row[b] + 10000*next_row[c] + 1000*next_row[d] + 100*next_row[e] + 10*next_row[f] + next_row[g];
			if (isprime(prime)) fout << prime << endl;
		}
	if (n == 8)
		loop(a, 4) loop(b, 4) loop(c, 4) loop(d, 4) loop(e, 4) loop(f, 4) loop(g, 4) loop(h, 4){
			int prime = 10000000*first_row[a] + 1000000*next_row[b] + 100000*next_row[c] + 10000*next_row[d] + 1000*next_row[e] + 100*next_row[f] + 10*next_row[g] + next_row[h];
			if (isprime(prime)) fout << prime << endl;
		}
}