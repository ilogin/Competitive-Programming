#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	map <string, set <string> > p;

	while (true){

		string a;
		getline(cin, a);
		if (a[0] == 0) break;

		string b;

		if (isupper(a[0])) p[b];
		else p[b].insert(a);
	}

	for (map <string, set <string> >::iterator it1 = p.begin(); it1 != p.end(); it1++)
		for (map <string, set <string> >::iterator it2 = p.begin(); it2 != p.end(); it2++)
			if (*it1 == *it2 && it1 != it2){
				p.erase(it1);
				p.erase(it2);
			}


	for (int i = 0; i < p.size(); i++)
		

	return 0;
}