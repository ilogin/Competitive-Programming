#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;
int queen[9], a(0), b(0), solution_count(1);
bool repeat(0);

bool check(int column, int row){
	for (int i = 1; i < column; i++){
		if (queen[i] == row) return false;
		if (abs(i - column) == abs(queen[i] - row)) return false;
	}
	return true;
}

void solve(int column){

	for (int row = 1; row < 9; row++)
		if (check(column, row)){
			queen[column] = row;

			if (column == 8 && queen[b] == a){
				printf("%2d      %d", solution_count++, queen[1]);
				for (int i = 2; i < 9; i++) printf(" %d", queen[i]);
				printf("\n");
			}
			else (solve(column+1));
		}
}

int main(){

	int t; cin >> t; while(t--){
		cin >> a >> b;
		if (repeat) printf("\n");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		memset(queen, 0, sizeof queen); solution_count = 1;
		solve(1);
		repeat = true;
	}

	return 0;
}
