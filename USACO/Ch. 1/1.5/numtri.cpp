#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

int ans = 0; int r = 0;
int triangles[1000][1000];
int dp[1000][1000];

int dfs(int x, int y){
	if (dp[x][y] != -1) return dp[x][y];
	if (x <= r)
		return dp[x][y] = triangles[x][y] + max(dfs(x+1, y), dfs(x+1, y+1));
	else return 0;
}

/*
ID: 11074501
TASK: numtri
LANG: C++
*/

int main(){
	ofstream fout ("numtri.out");
	ifstream fin ("numtri.in");

	memset(dp, -1, sizeof dp);
	fin >> r;
	loop(i, r) loop(j, i+1) fin >> triangles[i][j];
	fout << dfs(0, 0) << endl;
}