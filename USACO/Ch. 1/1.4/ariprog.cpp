/*
 ID: 11074501
 PROG: ariprog
 LANG: C++
 */
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;
int n;
int m;
struct Solucion{
    int a;
    int b;
};
int m2;
Solucion soluciones[1000005];
int c = -1;
bool serie[125005];

int numIteraciones( int p ){
    return (m2-p)/(n-1);
}

bool compara(Solucion a, Solucion b){
    bool ret_val;
    ret_val= a.b < b.b;
    return ret_val;
}
int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    fin>>n>>m;
    m2 = 2*m*m;
    for( int p = 0; p <= m; p++){
        for( int q = p; q <= m; q++ ){
            serie[(p*p) + (q*q)] = true;
        }
    }
    for( int p = 0; p <= m2-3; p++ ){
        if( serie[p] ){
            for( int j = 1; j <= numIteraciones(p); j++ ){
                int d = j;
                int cont = 1;
                while( (p+d <= m2) && serie[p+d] && cont < n ){
                    cont++;
                    d += j;
                }
                if( cont == n ){
                    c++;
                    soluciones[c].a = p;
                    soluciones[c].b = j;
                }
            }
        }
        
    }
    if( c == -1 ){
        fout<<"NONE"<<endl;
    }else{
        sort(soluciones, soluciones+c+1,compara);
        for( int i = 0; i <= c; i++ ){
            fout<< soluciones[i].a << " "<<soluciones[i].b<<endl;
        }
        
    }
    
    
    return 0;
}
