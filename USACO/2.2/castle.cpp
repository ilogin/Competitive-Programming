#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
int M, N;
int castle[51][51];
bool visited[51][51];

int room_count = 0;
int max_room = 0;
int max_removal = 0;
int ans_x = 0;
int ans_y = 0;
char max_wall = 'X';

/*
ID: 11074501
TASK: castle
LANG: C++
*/

int ff(int i, int j, bool removal){
	queue<pair<int,int>> bfs;
	bfs.push(make_pair(i, j));

	bool trav[51][51];
	memset(trav, false, sizeof trav);
	int room_size = 0;

	while(!bfs.empty()){
		pair<int,int> coord = bfs.front();
		bfs.pop();
		int x = coord.first;
		int y = coord.second;
		
		if (trav[y][x] == true){
			continue;
		}

		room_size += 1;

		// no wall to south
		if ( (castle[y][x] & 8) == 0){
			bfs.push(make_pair(x, y+1));
		}

		// no wall to east
		if ( (castle[y][x] & 4) == 0){
			bfs.push(make_pair(x+1, y));
		}

		// no wall to north
		if ( (castle[y][x] & 2) == 0){
			bfs.push(make_pair(x, y-1));
		}

		// no wall to west
		if ( (castle[y][x] & 1) == 0){
			bfs.push(make_pair(x-1, y));
		}

		trav[y][x] = true;
		if (removal == false) {
			visited[y][x] = true;
		}
	}

	return room_size;
}

void consider(int x, int y){

	if (visited[y][x] == false){
		room_count += 1;
		int room_size = ff(x, y, false);
		max_room = max(room_size, max_room);
	}

	bool update = false;
	int test = 0;

	if ( (castle[y][x] & 4) != 0 && x + 1 < M){
		castle[y][x] -= 4;
		test = ff(x, y, true);
		if ((test > max_removal) || 
			(test == max_removal && x < ans_x) || 
			(test == max_removal && x == ans_x && y > ans_y)){
				max_removal = test;
				max_wall = 'E';
				ans_x = x;
				ans_y = y;
			}
		castle[y][x] += 4;
	}

	if ( (castle[y][x] & 2) != 0 && y - 1 >= 0){
		castle[y][x] -= 2;
		test = ff(x, y, true);
		if ((test > max_removal) || 
			(test == max_removal && x < ans_x) || 
			(test == max_removal && x == ans_x && y > ans_y) ||
			(test == max_removal && x == ans_x && y == ans_y && max_wall == 'E')
			){
				max_removal = test;
				max_wall = 'N';
				ans_x = x;
				ans_y = y;
			}
		castle[y][x] += 2;
	}

}


int main(){
	ofstream fout ("castle.out");
	ifstream fin ("castle.in");

	fin >> M >> N;
	memset(castle, 0, sizeof castle);
	memset(visited, false, sizeof visited);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			fin >> castle[i][j];

	for (int y = 0; y < N; y++){
		for (int x = M-1; x >= 0; x--){
			consider(x, y);
		}
	}

	fout << room_count << endl;
	fout << max_room << endl;
	fout << max_removal << endl;
	fout << ans_y + 1 << " " << ans_x + 1 << " " << max_wall << endl;
}