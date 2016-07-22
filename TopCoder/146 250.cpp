#include <bits/stdc++.h>
using namespace std;

class YahtzeeScore{
public:
	int maxPoints(vector <int> toss){
		char text;
		cin >> text;

		int num;

		for (int i = 0; i < 5; i++){
			cin >> num >> text;
			toss.push_back(num);
		}

		int max = -1;

		for (int i = 1; i <= 6; i++){
			int sum = 0;
			for (int j = 0; j < 5; j++){
				if (toss[j] == i) sum += i;
				if (sum > max) max = sum;
			}
		}
		return max;
	}
};