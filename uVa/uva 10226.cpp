#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n;
	scanf("%d\n\n", &n);
	char name[35];

	while(n--){
		map <string, double> list;
		double total = 0;

		while (gets(name)){
			if (strlen(name) == 0) break;
			list[string(name)]++;
			total++;
		}

		for (map<string, double>::iterator it = list.begin(); it != list.end(); it++){
			printf("%s %.4lf\n", (*it).first.data(),
					(double) (*it).second / (double) total * 100.0);
		}

		if (n > 0) cout << endl;
	}

	return 0;
}