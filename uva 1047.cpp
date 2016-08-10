/*
ID: 1107501
TASK: milk2
LANG: C++
*/

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

	//Might be a good idea to compare and contrast my approach and someone else's
	int all, num; while (scanf("%d %d", &all, &num) != EOF){
		int towers[all]; for (int i = 0; i < all; i++) cin >> towers[i];
		int overlap; cin >> overlap; int PIE[overlap][all];
		for (int i = 0; i < overlap; i++){
			cin >> PIE[i][0];
			for (int j = 1; j <= PIE[i][0] + 1; j++)
				cin >> PIE[i][j];
		}

		int ans = 0;
		for (int i = 0; i < (1 << all); i++){
			int sum(0), count(0);
			for (int j = 0; j < all; j++){
				if (count == all) continue;
				if (i & (1 << j)){
					count++;
					sum += towers[j];
				}
			}

			//This is where the code gets funky; figure out a way to detract the running sum if there's an overlap
			//Possible solution: when getting the input of overlaps, make each line a bitset and use a map[bitset] = detract_value
					//Then in this section, iterate through the overlaps, use bit manipulation to see if the map[bitset] matches,
					//and detract if it does.
			for (int j = 0; j < overlap; j++){
				for (int k = 1; k <= PIE[j][0]; k++){
					if (!(i & (1 << PIE[j][k]))) continue;
					if (k == PIE[j][0]) sum -= PIE[j][k];
				}
			}

			//Output needs to be properly formatted.
			if (sum > ans) ans = sum;
		}

		printf("%d\n", ans);

	}

	return 0;
}
