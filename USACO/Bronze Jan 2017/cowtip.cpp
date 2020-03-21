#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
int grid[10][10];

/*
ID: 1107451
TASK: dualpal
LANG: C++
*/

void flip(int a, int b){
	loop(i, a+1) loop(j, b+1){
		if (grid[i][j] == 1) grid[i][j] = 0;
		else grid[i][j] = 1;
	}
}

int main(){

	ofstream fout ("cowtip.out");
	ifstream fin ("cowtip.in");

	int n;
	fin >> n;

	for (int i = 0; i < n; i++){
		string line; fin >> line;
		for (int j = 0; j < n; j++){
			char c = line[j];
			grid[i][j] = c - '0';
		}
	}

	int count = 0;
	for (int i = n-1; i >= 0; i--)
		for (int j = n-1; j >= 0; j--)
			if(grid[i][j] == 1){
				count++;
				flip(i,j);
			}

	fout << count << endl;

}