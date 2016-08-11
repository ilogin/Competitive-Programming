#include <bits/stdc++.h>
using namespace std;

class LittleElephantAndBallsAgain{
public:
	int getNumber(string S){
		
		int ans = 0;
		for (int i = 0; i < S.length(); i++)
			for(int j = S.length()-1;j > i; j--){
				for (int k = i; k <= j-1; j++)
					if (S[k] != S[k-1]) break;
			
			if (ans < j-i) ans = j-i;
		}
		return ans;
	}
};