#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	double h, u, d, f;
	h = -1;

	while (h != 0){
		cin >> h >> u >> d >> f;
		if (h == 0) break;

		double ha = 0;
		bool cont = true;
		int day = 0;
		double fatigue = (f * u * 0.01);

		while (cont == true){
			ha += u;
			u -= fatigue;
			if (u < 0) u = 0;
			day++;
			if (ha > h) break;
			ha -= d;
			if (ha < 0) cont = false;
		}

		if (cont == false) cout << "failure on day " << day;
		if (cont == true) cout << "success on day " << day;
		cout << endl;
	}

	return 0;
}