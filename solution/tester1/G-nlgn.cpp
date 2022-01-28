// O(nlogn) with fast implementation
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1000005
using namespace std;
using LL = long long;
int n,h[M],h2[M],v[M];
LL dp[M],tree[M],tree2[M];
inline int gn() {
    int res = 0;
    char g = getchar();
    while (!(g>=48 && g<=57)) g = getchar();
    while (g>=48 && g<=57) {
        res = res*10 + g-48;
        g = getchar();
    }
    return res;
}
void lisan() {
    memcpy(h2, h, sizeof(int)*(n+1));
    sort(h2+1, h2+n+1);
    REP(i,1,n) h[i] = lower_bound(h2+1, h2+n+1, h[i]) - h2;
}
inline int low(int x) { return x&-x; }
inline void upd(LL t[],int x,LL vv) {
    for (int i=x; i<=n; i+=low(i)) {
        if (t[i] < vv) {
            t[i] = vv;
        }
    }   
}
inline LL ask(LL t[],int x) {
    LL res = 0;
    for (int i=x; i>0; i-=low(i)) {
        if (t[i] > res) {
            res = t[i];
        }
    }
    return res;
}
int main()
{
    n = gn();
    REP(i,1,n) h[i] = gn();
    REP(i,1,n) v[i] = gn();
    lisan();

    REP(i,1,n) {
        dp[i] = ask(tree2, n+1-h[i]-1) + v[i];
        upd(tree, h[i], dp[i]);
        upd(tree2, n+1-h[i], ask(tree, h[i]-1));
    }
    printf("%lld\n", *max_element(dp+1, dp+n+1));

    return 0;
}
