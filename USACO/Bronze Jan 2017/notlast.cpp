#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)
typedef pair<string, int> ii;
typedef vector<ii> vii;
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)

/*
ID: 1107451
TASK: dualpal
LANG: C++
*/

bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second < b.second);
}

int main(){

	ofstream fout ("notlast.out");
	ifstream fin ("notlast.in");

	int names[7]; loop(i, 7) names[i] = 0;

	int n; fin >> n; loop(i,n){
		string cow; int milk; fin >> cow >> milk;
		if (cow == "Bessie") names[0] += milk;
		if (cow == "Elsie") names[1] += milk;
		if (cow == "Daisy") names[2] += milk;
		if (cow == "Gertie") names[3] += milk;
		if (cow == "Annabelle") names[4] += milk;
		if (cow == "Maggie") names[5] += milk;
		if (cow == "Henrietta") names[6] += milk;
	}
    
	int small = 101000;
	loop(i, 7) if (small > names[i]) small = names[i];

	vii real_names;
	real_names.push_back(make_pair("Bessie", names[0]));
	real_names.push_back(make_pair("Elsie", names[1]));
	real_names.push_back(make_pair("Daisy", names[2]));
	real_names.push_back(make_pair("Gertie", names[3]));
	real_names.push_back(make_pair("Annabelle", names[4]));
	real_names.push_back(make_pair("Maggie", names[5]));
	real_names.push_back(make_pair("Henrietta", names[6]));
    
    sort(real_names.begin(), real_names.end(), sortbysec);
    bool tie = true;
    TRvii(real_names, it)
    	if (it->second > small && tie) {
    		fout << it->first << endl;
    		tie = false;
    	}
    if (tie) fout << "Tie" << endl;
}
