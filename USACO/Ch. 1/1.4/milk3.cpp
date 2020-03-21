#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

int a, b, c;
queue<int> thing;
bool space[20][20][20] = {0};
set<int>ans;

/*
ID: 1107451
TASK: milk3
LANG: C++
*/

void reload(int d, int e, int f){
	if (!space[d][e][f]){
		space[d][e][f] = true;
		if (d == 0) ans.insert(f);
		thing.push(d); thing.push(e); thing.push(f);
	}
}

void process(int one, int two, int three){
	if (one > 0){
		if (c < three + one) reload(one + three - c, two, c);
		if (c >= three + one) reload(0, two, three + one);
		if (b < two + one) reload(one + two - b, b, three);
		if (b >= two + one) reload(0, two + one, three);
	}
	if (two > 0){
		if (c < three + two) reload(one, two + three - c, c);
		if (c >= three + two) reload(one, 0, three + two);
		if (a < two + one) reload(a, one + two - a, three);
		if (a >= two + one) reload(one + two, 0, three);
	}
	if (three > 0){
		if (a < three + one) reload(a, two, one + three - a);
		if (a >= three + one) reload(three + one, two, 0);
		if (b < two + three) reload(one, b, three + two - b);
		if (b >= two + three) reload(one, two + three, 0);
	}
}

void bfs(int d, int e, int f){
	thing.push(d); thing.push(e); thing.push(f);
	while(!thing.empty()){
		int one = thing.front(); thing.pop();
		int two = thing.front(); thing.pop();
		int three = thing.front(); thing.pop();
		process(one, two, three);
	}
}

int main(){
	ofstream fout ("milk3.out");
	ifstream fin ("milk3.in");
	fin >> a >> b >> c;

	bfs(0, 0, c);
	vector<int>complete;
	for (set <int>::iterator it = ans.begin(); it != ans.end(); it++){
		complete.push_back(*it);
	}
	loop(i, complete.size()-1){
		fout << complete[i] << " ";
	}
	fout << complete[complete.size()-1] << endl;
}