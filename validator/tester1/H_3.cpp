#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc,char *argv[])
{
    registerValidation(argc, argv);

    int n = inf.readInt(1,10000);
    inf.readChar('\n');

    vector<int> in[3];
    REP(i,1,6*n) {
        int x = inf.readInt(-100000000, 100000000);
        inf.readSpace();
        int y = inf.readInt(-100000000, 100000000);
        inf.readChar('\n');

        ensuref(x!=0, "x should not = 0");
        ensuref(y==2 || y==0 || y==-2, "y should be 2,0,-2");
        if (y==2) in[2].push_back(x);
        else if (y==0) in[1].push_back(x);
        else in[0].push_back(x);
    }
    inf.readEof();

    REP(i,0,2) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int j: in[i]) {
            if (j>0) cnt1++;
            else cnt2++;
        }
        ensuref(cnt1==n, "");
        ensuref(cnt2==n, "");
    }

    return 0;
}
