#include <bits/stdc++.h>
using namespace std;

class Arrfix{
public:
	int mindiff(vector <int> A, vector <int> B, vector <int> F){
	
		int length = A.size();
		bool dup[length+1];
		for (int i = 0; i < length; i++) dup[i] = false;
	
		if (F.size() > 0){
		for (int i = 0; i < F.size(); i++){
			bool check = false;
			for (int j = 0; j < B.size(); j++){
				if (B[j] == F[i] && dup[j] != true && A[j] != B[j]){A[j] = F[i];check=true; dup[j] = true; break;}
			}
			if (!check)
				for (int k = 0; k < length; k++) 
					if (dup[k] != true){dup[k] = true; A[k] = F[i]; break;}
		}
		}
		int ans = 0;
		for (int i = 0; i < length; i++)
			if (A[i] != B[i]) ans++;
			
		return ans;
	}
};