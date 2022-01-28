#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc,char *argv[])
{
    registerValidation(argc, argv);

    int MX = 200000;
    int n = inf.readInt(1, MX);
    inf.readChar('\n');

    REP(i,1,n) {
        int x = inf.readInt(0, 1000000000);
        if (i==n) inf.readChar('\n');
        else inf.readSpace();
    }

    REP(i,1,n) {
        int x = inf.readInt(1, 100000);
        if (i==n) inf.readChar('\n');
        else inf.readSpace();
    }

    inf.readEof();

    return 0;
}
