#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
int m, n;
int space[51][51];
bool visited[51][51];
int counter = 0;

/*
ID: 11074501
TASK: castle
LANG: C++
*/

void room(int a, int b){

	if (visited[a][b]) return;
	if (a < 0 || b < 0 || a >= n || b >= m) return;
	visited[a][b] = true;
	counter++;

	int dummy = space[a][b];

	if (dummy < 8) room(a+1, b);
	else dummy -= 8;

	if (dummy < 4) room(a, b+1);
	else dummy -= 4;

	if (dummy < 2) room(a-1, b);
	else dummy -= 2;

	if (dummy < 1) room(a, b-1);
}

int main(){
/*
	ofstream fout ("castle.out");
	ifstream fin ("castle.in");
*/

	cin >> m >> n;
	memset(space, 0, sizeof space);
	memset(visited, false, sizeof visited);
	loop(i, n) loop(j, m) cin >> space[i][j];

	int num_room = 0;
	int max_size = 0;

	loop(i, n) loop(j, m){
		counter = 0;
		room(i, j);
		if (counter > 0) num_room++;
		if (counter > max_size) max_size = counter;
	}

	cout << num_room << endl << max_size << endl;
}