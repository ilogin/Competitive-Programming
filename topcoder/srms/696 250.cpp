#include <bits/stdc++.h>
using namespace std;

class Ropestring{
public:
	string makerope(string s){
		
		string ans;
		
		int count[51]; int a = 0; int b = 0;
		for (int i = 0; i < 51; i++) count[i] = 0;
		for (int i = 0; i <= s.length(); i++){
			if (s[i] == '-') a++;
			else {
				count[a]++;
				a = 0;
				b++;
			}
		}
		
		for (int i = 50; i > 0; i -= 2){
			while (count[i]) {
			
			for (int j = i; j > 0; j--)
				ans += '-';
				
			ans += '.'; b--;
			count[i]--;
			}
		}
		
		for (int i = 49; i > 0; i -= 2){
			while (count[i]) {
			
			for (int j = i; j > 0; j--)
				ans += '-';
				
			ans += '.'; b--;
			
			count[i]--;
			}
		}
		b--;
		
		while(b){
		ans+='.';
		b--;
		}
	
		return ans;
	}

};