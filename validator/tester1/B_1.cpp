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

    LLU MX = 9LLU;
    int t = inf.readInt(1, 9);
    inf.readChar('\n');
    while (t--) {
        LLU n = inf.readUnsignedLong(1LLU, MX);
        inf.readChar('\n');
    }
    inf.readEof();

    return 0;
}


