#include <bits/stdc++.h>
#define ll long long
#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;

vector<int>current_ans,ans;
int current_n;

int solve(int n, int amt, int arr[], int a, int b){

	if (current_n + arr[b] > n){
		//check

		if (current_ans.size() > ans.size()){
			ans.clear();
			for (int i = 0; i < current_ans.size(); i++) ans.pb(current_ans[i]);
		}

		a++;
		b = a;
	}

	current_ans.pb(arr[b]);
	solve(n, amt, arr, a, b+1);

}

int main(){

	int n;
	while (cin >> n){
		current_n = 0; current_ans.clear(); ans.clear();
		int amt; cin >> amt;
		int arr[amt];
		for (int i = 0; i < amt; i++) cin >> arr[i];

		solve(n, amt, arr, 0, 0);

		for (int i = 0; i < ans.size(); i++)
			printf("%d ", arr[i]);

		cout << endl;
	}

	return 0;
}