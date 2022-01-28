#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc,char *argv[])
{
    registerValidation(argc, argv);

    int t = inf.readInt(1,3000);
    inf.readSpace();
    int n = inf.readInt(1,10000);
    inf.readChar('\n');

    int fr = 0;
    REP(i,1,n) {
        int x = inf.readInt(0, 1000000000);
        if (i==n) inf.readChar('\n');
        else inf.readSpace();

        ensuref(x > fr, "should increase");
        ensuref(x-fr<=t, "diff should <= t");
        fr = x;
    }

    inf.readEof();

    return 0;
}
