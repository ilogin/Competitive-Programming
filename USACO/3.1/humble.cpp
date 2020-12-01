/*
ID: 11074501
TASK: humble
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    istringstream iss;

    ifstream fin ("humble.in");

    int K, N;
    getline(fin, line);
    iss.clear();
    iss.str(line);
    iss >> K >> N;
    
    int primes[K];
    long humbles[N+1];
    int p_h[K];
    memset(humbles, 0, sizeof humbles);
    memset(p_h, 0, sizeof p_h);
    humbles[0] = 1;

    while(getline(fin, line)){
        iss.clear();
        iss.str(line);
        for (int i = 0; i < K; i++){
            iss >> primes[i];
        }
    }

    for(int i = 0; i < N; i++){
        long last = humbles[i];
        long next_humble = -1;

        int min_p = -1;

        for (int k = 0; k < K; k++){
            long curr = primes[k] * humbles[p_h[k]];
            while (curr <= last){
                p_h[k] += 1;
                curr = primes[k] * humbles[p_h[k]];
            }

            if (next_humble == -1 || curr < next_humble){
                next_humble = curr;
                min_p = k;
            }
        }

        p_h[min_p] += 1;

        humbles[i+1] = next_humble;
    }


    ofstream fileout ("humble.out");
    fileout << humbles[N] << endl;
    fileout.close();

    return (0);
}
