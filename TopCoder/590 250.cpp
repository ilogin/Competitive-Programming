#include <bits/stdc++.h>
using namespace std;

class FoxAndGomoku{
public:
	string win(vector <string> board){
		int n = board.size();
		bool ans = false;

		/*Original Mistakes:
		Segmentation fault, used

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)

		for all checks.

		Assumed that the board is a square and used

		int n = board.size();

		instead of

		int n = board.size();
		int m = board[0].length();

		Good programming practice:
			if (board[i][j] == 'o') &&
			(board[i+1][j+1] == 'o') &&
			...
			board([i+4][j+4] == 'o') ans = true;

		Bad (i don't know if it's incorrect) programming practice:
			if (board[i][j] == 'o' == board[i-1][j] == board[i-2][j] == board[i-3][j] == board[i-4][j]) ans = true;


		*/

		//down
		for (int i = 0; i < n-5; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 'o' == board[i-1][j] == board[i-2][j] == board[i-3][j] == board[i-4][j]) ans = true;

		//up
		for (int i = n; i < 5; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 'o' == board[i+1][j] == board[i+2][j] == board[i+3][j] == board[i+4][j]) ans = true;

		//right
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n-5; j++)
				if (board[i][j] == 'o' == board[i][j+1] == board[i][j+2] == board[i][j+3] == board[i][j+4]) ans = true;

		//left
		for (int i = 0; i < n; i++)
			for (int j = n; j < 5; j++)
				if (board[i][j] == 'o' == board[i][j-1] == board[i][j-2] == board[i][j-3] == board[i][j-4]) ans = true;

		//upright
		for (int i = n; i < 5; i++)
			for (int j = 0; j < n-5; j++)
				if (board[i][j] == 'o' == board[i+1][j+1] == board[i+2][j+2] == board[i+3][j+3] == board[i+4][j+4]) ans = true;

		//upleft
		for (int i = n; i < 5; i++)
			for (int j = n; j < 5; j++)
				if (board[i][j] == 'o' == board[i+1][j-1] == board[i+2][j-2] == board[i+3][j-3] == board[i+4][j-4]) ans = true;

		//downright
		for (int i = 0; i < n-5; i++)
			for (int j = 0; j < n-5; j++)
				if (board[i][j] == 'o' == board[i-1][j+1] == board[i-2][j+2] == board[i-3][j+3] == board[i-4][j+4]) ans = true;

		//downleft
		for (int i = 0; i < n-5; i++)
			for (int j = n; j < 5; j++)
				if (board[i][j] == 'o' == board[i-1][j-1] == board[i-2][j-2] == board[i-3][j-3] == board[i-4][j-4]) ans = true;

	if (ans == false)
		return "not found";


	if (ans == true)
		return "found";
	}
};



int main(){

	bool ans = false;
	vector <string> board;

	int n;
	//board = n by n

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			//down
			if (board[i][j] == board[i-1][j] == board[i-2][j] == board[i-3][j] == board[i-4][j] == 'o') ans = true;

			//up
			if (board[i][j] == board[i+1][j] == board[i+2][j] == board[i+3][j] == board[i+5][j] == 'o') ans = true;

			//right
			if (board[i][j] == board[i][j+1] == board[i][j+2] == board[i][j+3] == board[i][j+5] == 'o') ans = true;

			//left
			if (board[i][j] == board[i][j-1] == board[i][j-2] == board[i][j-3] == board[i][j-4] == 'o') ans = true;

			//upright
			if (board[i][j] == board[i+1][j+1] == board[i+2][j+2] == board[i+3][j+3] == board[i+5][j+5] == 'o') ans = true;

			//upleft
			if (board[i][j] == board[i+1][j-1] == board[i+2][j-2] == board[i+3][j-3] == board[i+5][j-4] == 'o') ans = true;

			//downright
			if (board[i][j] == board[i-1][j+1] == board[i-2][j+2] == board[i-3][j+3] == board[i-4][j+5] == 'o') ans = true;

			//downleft
			if (board[i][j] == board[i-1][j-1] == board[i-2][j-2] == board[i-3][j-3] == board[i-4][j-4] == 'o') ans = true;
		}

	if (ans == false)
		cout << "not found";


	if (ans == true)
		cout << "found";


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