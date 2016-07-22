#include <bits/stdc++.h>
using namespace std;

class DivisorDigits{
public:
	int howMany(int number){
		stringstream ss;
		string dummy;

		ss << number;
		ss >> dummy;

		int ans = 0;

		for (int i = 0; i < dummy.length(); i++){
			int use = dummy[i] - 48;
			if (use != 0 && number % use == 0) ans++;
		}

		return ans;
	}
};