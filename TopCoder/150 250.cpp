#include <bits/stdc++.h>
using namespace std;

class WidgetRepairs{
public:
	int days(vector <int> arrivals, int numPerDay){
		int sum = arrivals[0];
		int day = 0;

		for (int i = 0; i < arrivals.size(); i++){
			if (i > 0) sum += arrivals[i];
			if (sum > 0 || arrivals[i] > 0) day++;
			sum -= numPerDay;
			if (sum < 0) sum = 0;
		}

		if (sum > 0){
			sum -= numPerDay;
			day++;
		}

		return day;
	}
};


int main(){

	return 0;
}

/*
ID: 11074501
PROG: test
LANG: C++
*/

/*
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);	
*/