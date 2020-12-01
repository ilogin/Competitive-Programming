#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

long long dp[10001][25];
int V, N;
int coins[25];

/*
ID: 11074501
TASK: money
LANG: C++
*/


int main(){
	ofstream fout ("money.out");
	ifstream fin ("money.in");

	fin >> V >> N;

	memset(dp, 0, sizeof dp);

	int counter = 0;
	while(!fin.eof()){
		string line;
		getline(fin, line);

		istringstream iss(line);
		int num = 0;
		while (iss >> num){
			coins[counter] = num;
			counter++;
		}
	}

	for (int i = 0; i <= N; i += coins[0]){
		dp[i][0] = 1;
	}

	for (int i = 1; i < V; i++){
		for (int j = 0; j <= N; j++){
			dp[j][i] = dp[j][i-1];
		}


		for (int j = 0; j <= N; j++){
			int itself = 1;

			while( (j + (itself*coins[i])) <= N){
				if (dp[j][i-1] > 0){
					dp[j + (itself * coins[i])][i] += dp[j][i-1];
				}
				itself++;
			}
		}
	}
	
	fout << dp[N][V-1] << endl;
}