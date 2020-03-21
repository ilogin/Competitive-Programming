#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 11074501
TASK: pprime
LANG: C++
*/

bool isprime(int test){
	for (int i = 2; i <= sqrt(test); i++) if (test % i == 0) return false;
	return true;
}

int main(){
	ofstream fout ("pprime.out");
	ifstream fin ("pprime.in");

	int a, b; fin >> a >> b;

	int upper_bound = 0; int dummy = b;
	while(true){
		dummy /= 10;
		upper_bound++;
		if(dummy == 0) break;
	}

	if (upper_bound >= 1)
		for (int d1 = 1; d1 <= 9; d1 += 2) if (d1 <= b && isprime(d1) && d1 >= a) fout << d1 << endl;

	if (upper_bound >= 2 && 11 <= b && 11 >= a) fout << 11 << endl;

	if (upper_bound >= 3){
		for (int d1 = 1; d1 <= 9; d1 += 2){
			loop(d2, 10){
				int palindrome = 100*d1 + 10*d2 + d1;
				if (palindrome <= b && isprime(palindrome) && palindrome >= a) fout << palindrome << endl;
			}
		}
	}

	if (upper_bound >= 5){
		for (int d1 = 1; d1 <= 9; d1 += 2){
			loop(d2, 10){
				loop(d3, 10){
					int palindrome = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
					if (palindrome <= b && isprime(palindrome) && palindrome >= a) fout << palindrome << endl;

				}
			}
		}
	}

	if (upper_bound >= 7){
		for (int d1 = 1; d1 <= 9; d1 += 2){
			loop(d2, 10){
				loop(d3, 10){
					loop(d4, 10){
						int palindrome = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
						if (palindrome <= b && isprime(palindrome) && palindrome >= a) fout << palindrome << endl;
					}
				}
			}
		}
	}

}