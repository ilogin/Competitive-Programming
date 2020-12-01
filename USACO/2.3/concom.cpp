#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

int portfolio[100][100];

/*
ID: 11074501
TASK: concom
LANG: C++
*/


int main(){
	ofstream fout ("concom.out");
	ifstream fin ("concom.in");

	int n;
	fin >> n;

	memset(portfolio, 0, sizeof portfolio);
	map<int, vector<int>>owns;

	while(n--){
		int i, j, p;
		fin >> i >> j >> p;
		portfolio[i][j] = p;
		if (p > 50) owns[i].push_back(j);
	}

	// bfs to update owns
	for (int i = 0; i < owns.size(); i++){
		queue<int>bfs;
		bfs.push(i);

		while(!bfs.empty()){
			int thing = bfs.front();
			bfs.pop();

			vector<int> children = owns[thing];

			for (int j = 0; j < children.size(); j++){
				bfs.push(children[j]);
				if (find(owns[i].begin(), owns[i].end(), children[j]) == owns[i].end()){
					owns[i].push_back(children[j]);
				}
			}
		}
		
		vector<int>updates;
		for (int j = 0; j < owns[i].size(); j++){
			int new_company = owns[i][j];
			for (int k = 0; k < 100; k++){
				portfolio[i][k] += portfolio[new_company][k];
				
				if (portfolio[i][k] > 50 && 
				find(owns[i].begin(), owns[i].end(), k) == owns[i].end() && 
				find(updates.begin(), updates.end(), k) == updates.end()){
					updates.push_back(k);
				}
			}
		}
		
		for (int j = 0; j < updates.size(); j++) owns[i].push_back(updates[j]);
	}
	
	bool printed[100][100];
	memset(printed, false, sizeof printed);
	
	for (int i = 0; i < owns.size(); i++){
		sort (owns[i].begin(), owns[i].end());
		for (int j = 0; j < owns[i].size(); j++){
			if (printed[i][j] == false && printed[j][i] == false){
				fout << i << " " << owns[i][j] << endl;
			}
			printed[i][j] = true;
			printed[j][i] = true;
		}
	}
}