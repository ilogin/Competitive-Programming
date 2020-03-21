#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)

/*
ID: 1107451
TASK: milk
LANG: C++
*/

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.first < b.first);
}

int main(){
	ofstream fout ("milk.out");
	ifstream fin ("milk.in");

	int n, m; fin >> n >> m;
	vii farmers;
	for (int i = 0; i < m; i++){
		int a, b; fin >> a >> b; farmers.push_back(make_pair(a, b));
	}

	sort(farmers.begin(), farmers.end(), sortbysec);
	
	int cost = 0;
	TRvii(farmers, it){
		if (n > 0){
			cost += it->first * min(it->second, n);
			n -= it->second;
		}
	}

	fout << cost << endl;

}