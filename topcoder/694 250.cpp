#include <bits/stdc++.h>
using namespace std;

class MakingPairs{
public:
	int get(vector <int> card){
		
		int ans = 0;
		
		for (int i = 0; i < card.size(); i++)
			ans += card[i]/2;
		
		return ans;
	}
};