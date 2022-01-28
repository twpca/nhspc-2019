#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
#define MOD 1000000007
using namespace std;
using LL = unsigned long long;
struct Mat {
    LL x[2][2];
    Mat () {
        MSET(x, 0);
    }
    Mat operator * (Mat a) {
        Mat res;
        REP(i,0,1)REP(j,0,1)REP(k,0,1) {
            res.x[i][j] += x[i][k] * a.x[k][j];
            res.x[i][j] %= MOD;
        }
        return res;
    }
    Mat pow(LL y) {
        if (y==0) {
            Mat res;
            res.x[0][0] = res.x[1][1] = 1;
            return res;
        }
        if (y==1) {
            return *this;
        }

        Mat tmp = (*this).pow(y/2);
        if (y%2) return tmp*tmp*(*this);
        return tmp*tmp;
    } 
}mat;
int main()
{
    mat.x[0][0] = 3;
    mat.x[0][1] = 8;
    mat.x[1][0] = 1;
    mat.x[1][1] = 3;

    int t;
    LL n;
    scanf("%d", &t);
    while (t--) {
        scanf("%llu", &n);

        Mat tmp = mat.pow(n);

        LL a = tmp.x[0][0];
        LL b = tmp.x[1][0];
        a = (a+1) * 500000004LL % MOD;
        printf("%llu %llu\n",a,b);
    }

    return 0;
}

