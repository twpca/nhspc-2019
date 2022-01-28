#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc,char *argv[])
{
    registerValidation(argc, argv);

    int n = inf.readInt(3,100000);
    inf.readSpace();
    int st = inf.readInt(0, n-2);
    inf.readSpace();
    long long w = inf.readLong(1, 1000000000000LL);
    inf.readChar('\n');

    vector<int> in;
    REP(i,1,n) {
        int x = inf.readInt(1, 1000000000); //TODO
        in.push_back(x);
        if (i==n) inf.readChar('\n');
        else inf.readSpace();
    }
    inf.readEof();

    ensuref((long long)min(in[0], in[n-1]) * (n-1) >= w, "water > total");

    sort(in.begin(), in.end());
    REP(i,1,n-1) ensuref(in[i]!=in[i-1], "same height");

    return 0;
}
