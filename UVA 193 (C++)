#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;
int n, k, graph[101][101];
vector<int>nodes, answer;

bool place(int node){
	for (int i = 1; i <= n; i++)
		if (graph[node][i] == 1 && find (nodes.begin(), nodes.end(), i) != nodes.end()) return false;
	return true;
}

void solve(int pos){
	for (int node = pos; node <= n; node++)
		if (place(node)){
			nodes.pb(node);
			if (nodes.size() > answer.size()) answer = nodes;

			solve(node+1);

			nodes.pop_back();
		}
}

int main(){

	int t; cin >> t; while(t--){
		cin >> n >> k;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				graph[i][j] = 0;
		nodes.clear(); answer.clear();

		while(k--){
			int a, b; cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		solve(1);

		printf("%d\n%d", answer.size(), answer[0]);
		for (int i = 1; i < answer.size(); i++) printf(" %d", answer[i]);

		printf("\n");
	}

	return 0;
}
