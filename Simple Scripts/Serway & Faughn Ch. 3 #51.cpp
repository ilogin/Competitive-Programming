#include <bits/stdc++.h>
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){

	vii coordinates;

	coordinates[0] = {30, -20};
	coordinates[1] = {60, 80};
	coordinates[2] = {-10, -10};
	coordinates[3] = {40, -30};
	coordinates[4] = {-70, 60};

	ii current = {30, -20};

	for (int i = 1; i < 5; i++){
		int x = current.first;
		int y = current.second;
		int delta_x = coordinates[i].first - x;
		int delta_y = coordinates[i].second - y;
		int dist = sqrt(pow((coordinates[i].first - x),2) + pow((coordinates[i].second - y),2));
		dist /= 2;
	}

	return 0;
}