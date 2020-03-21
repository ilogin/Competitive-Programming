#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 1107451
TASK: frac1
LANG: C++
*/

struct Fraction{
	int a, b; float c;
};

bool compara(Fraction a, Fraction b){
	return a.c < b.c;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
	ofstream fout ("frac1.out");
	ifstream fin ("frac1.in");
	
	int n; fin >> n;
	bool space[2*n][2*n];
	loop(i, 2*n) loop(j, 2*n) space[i][j] = false;
	Fraction fraction[160*160];
	int d = 0;

	//1/3 2/3 3/3
	//1/2 2/2
	//1/1

	for (int row = 1; row <= n; row++){
		int dummy = row;
		for (int column = 1; column <= row; column++){
			int numerator = column;
			int denominator = n - dummy + 1;
			if (gcd(numerator, denominator) == 1 || numerator == 1)
				if (!space[numerator][denominator]){
					space[numerator][denominator] = false;
					fraction[d].a = numerator;
					fraction[d].b = denominator;
					float thing = numerator;
					thing /= denominator;
					fraction[d].c = thing;
					d++;
				}
			dummy--;
		}
	}
	sort(fraction, fraction + d, compara);

	fout << "0/1" << endl;
	loop(i, d) fout << fraction[i].a << "/" << fraction[i].b << endl;

}