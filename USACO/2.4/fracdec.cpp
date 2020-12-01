#include <bits/stdc++.h>
using namespace std;
#define loop(i, a) for (int i = 0; i < a; i++)

int portfolio[100][100];

/*
ID: 11074501
TASK: fracdec
LANG: C++
*/


int main(){
  ofstream fout ("fracdec.out");
  ifstream fin ("fracdec.in");

  string line;
  istringstream iss;
  
  int N, D;
  while(getline(fin, line)){
    iss.clear();
    iss.str(line);
    iss >> N >> D;
  }

  map<int, int> remainders;
  vector<pair<int, int>> quotients;

  int integer = floor(N / D);
  int rem = N - (integer * D);

  string dec_str = "";

  if (rem == 0){
    dec_str = "0";
  }

  int repeat = -1;

  while (rem != 0){
    if (remainders.find(rem) != remainders.end()){
      repeat = rem;
      break;
    }

    int quotient = floor( (rem*10) / D );
    remainders.insert({rem, 1});
    quotients.push_back(make_pair(quotient, rem));

    rem = (rem*10) - (D * quotient);
  }

  if (dec_str != "0"){
    if (repeat > -1){
      int beg_idx = 0;
      for (int i = quotients.size() - 1; i >= 0; i--){
        if (quotients[i].second == repeat){
          beg_idx = i;
          break;
        }
      }

      dec_str = "";
      for (int i = 0; i < quotients.size(); i++){
        if (i == beg_idx){
          dec_str += "(";
        }
        dec_str += to_string(quotients[i].first);
      }
      dec_str += ")";
    }
    else{
      for (int i = 0; i < quotients.size(); i++){
        dec_str += to_string(quotients[i].first);
      }
    }
  }

  string ans = to_string(integer) + "." + dec_str;
  for (int i = 0; i < ans.length(); i++){
    if (i > 0 && i % 76 == 0){
      fout << endl;
    }
    fout << ans[i];
  }
  
  fout << endl;

}