#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LLU = unsigned long long;
int main(int argc,char *argv[])
{
    registerValidation(argc, argv);

    int k = inf.readInt(1, 1000000000);
    inf.readChar('\n');

    int n = inf.readInt(1,50);
    inf.readSpace();
    int m = inf.readInt(1,300000);
    inf.readChar('\n');
    ensuref(n*m<=300000, "n*m <= 300000");

    REP(i,1,n) {
        REP(j,1,m) {
            int x = inf.readInt(-3000, 3000);
            if (j!=m) inf.readSpace();
            else inf.readChar('\n');
        }
    }
    inf.readEof();

    return 0;
}


