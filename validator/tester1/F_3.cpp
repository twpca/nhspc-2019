#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc,char *argv[])
{
    registerValidation(argc, argv);

    int MX = 600;
    int n = inf.readInt(1, MX);
    vector<int> in;
    inf.readChar('\n');

    REP(i,1,n) {
        int x = inf.readInt(1, n);
        if (i==n) inf.readChar('\n');
        else inf.readSpace();
        in.push_back(x);
    }

    inf.readEof();

    sort(in.begin(), in.end());
    REP(i,0,n-1) {
        ensuref(in[i]==i+1, "input must be a permutation");
    }

    return 0;
}

