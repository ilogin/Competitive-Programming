#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;

int main(){

	int p, q, r, s, t, u;
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		float a, b, x;
		a = 0; b = 1; x = 0.5;

		if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9 || p+r+u<0){
			printf("No solution\n");
			continue;
		}

		for (int i = 0; i < 50; i++){
			float c = ((p * exp (-x) ) + (q * sin(x)) + (r * cos(x)) + s*(tan(x)) + (t*x*x) + u);
			if (c < 0) b = x;
			if (c > 0) a = x;
			x = (a + b)/2;
		}

		printf("%.4f\n", x);
	}

	return 0;
}
