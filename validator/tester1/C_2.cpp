#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n;
vector<int> e[M];

int dfs(int cur) {
    int res = 1;
    for (int i:e[cur]) res += dfs(i);
    return res;
}

int main(int argc,char *argv[])
{
    registerValidation(argc, argv);
    
    n = inf.readInt(1,200000);
    inf.readChar('\n');

    REP(i,1,n) {
        int x = inf.readInt(0,10);
        if (i==n) inf.readChar('\n');
        else inf.readSpace();
    }
    REP(i,1,n-1) {
        int x = inf.readInt(0, n-1);
        inf.readSpace();
        int y = inf.readInt(0, n-1);
        inf.readChar('\n');
        ensuref(x!=y, "x!=y");
        e[x].push_back(y);
    }
    inf.readEof();

    ensuref(dfs(0)==n, "0 should connect to all other vertices");

    
    return 0;
}
