#include <bits/stdc++.h>
using namespace std;

class FixedPointTheorem{
public:
	double cycleRange(double R){
		double x = 0.25;

		for (int i = 1; i <= 200000; i++){
			x = R * x * (1-x);
		}

		double ma, mi;
		ma = 0.0;
		mi = 1.0;

		for (int i = 1; i < 1000; i++){
			x = R * x * (1-x);
			if (x > ma) ma = x;
			if (x < mi) mi = x;
		}

		return (ma - mi);

	}
};