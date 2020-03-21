#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

/*
ID: 1107451
TASK: transform
LANG: C++
*/

int n(0);
char Bryan[10][10], want[10][10], fake[10][10], fakest[10][10];

//1: 90 deg rotation
void one(char dummy[][10]){
	loop(i, n) loop(j, n) fake[j][n-i-1] = dummy[i][j];
}

//2: 180 deg rotation
void two(char dummy[][10]){
	loop(i, n) loop(j, n) fake[n-1-i][n-1-j] = dummy[i][j];
}

//3: 270 deg rotation
void three(char dummy[][10]){
	loop(i, n) loop(j, n) fake[n-j-1][i] = dummy[i][j];
}

//4: horizontal reflection
void four(char dummy[][10]){
	loop(i, n) loop (j, n) fake[i][n-j-1] = dummy[i][j];
}

void reset(){
	loop(i, n) loop (j, n) fake[i][j] = Bryan[i][j];
}

void combo(){
	loop(i, n) loop(j, n) fakest[i][j] = fake[i][j];
}

bool check(){
	loop (i, n) loop (j, n)
			if (fake[i][j] != want[i][j])
				return false;
	return true;
}

int main(){

	ofstream fout ("transform.out");
	ifstream fin ("transform.in");

	fin >> n;
	loop(i, n) loop (j, n) fin >> Bryan[i][j];
	loop(i, n) loop (j, n) fin >> want[i][j];

	while(true){
		one(Bryan); if (check()) {fout << "1\n"; break;}
		two(Bryan); if (check()) {fout << "2\n"; break;}
		three(Bryan); if (check()) {fout << "3\n"; break;}
		four(Bryan); if (check()) {fout << "4\n"; break;}
		four(Bryan); combo(); one(fakest); if (check()) {fout << "5\n"; break;}
		four(Bryan); combo(); two(fakest); if (check()) {fout << "5\n"; break;}
		four(Bryan); combo(); three(fakest); if (check()) {fout << "5\n"; break;}
		reset(); if (check()){fout << "6\n"; break;}
		fout << "7\n"; break;
	}
}