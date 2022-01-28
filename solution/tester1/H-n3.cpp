// O(n^3)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 10005
using namespace std;
using LL = long long;
int n;
LL in[3][2*M],sum[3][2*M];

void init() {
    vector<int> ar[3];
    ar[0].clear();
    ar[1].clear();
    ar[2].clear();

    REP(i,1,6*n) {
        int x,y;
        scanf("%d %d",&x,&y);
        if (y==-2) ar[0].push_back(x);
        if (y==0) ar[1].push_back(x);
        if (y==2) ar[2].push_back(x);
    }
    REP(i,0,2) sort(ar[i].begin(), ar[i].end());

    REP(i,0,2) REP(j,1,n*2) {
        in[i][j] = ar[i][j-1];
        sum[i][j] = sum[i][j-1] + in[i][j];
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        init();

        auto gs = [](int id,int x) {
            LL fr = sum[id][x];
            LL bk = sum[id][2*n] - sum[id][2*n-x];
            return abs(fr) + abs(bk);
        };

        auto gs2 = [](int id,int x,int y) {
            LL fr = sum[id][y] - sum[id][x-1];
            return abs(fr);
        };
        
        LL ans = 0;
        REP(i,0,n) REP(j,0,n-i) REP(k,0,n-i-j) {
            int l = n-i-j-k;
            LL tmp = 2*gs(0,i) + 2*gs(2,j);
            tmp += 2*gs2(1,1,k) + 1*gs2(0,2*n-i-k+1,2*n-i) + 1*gs2(2,2*n-j-k+1,2*n-j);
            tmp += 2*gs2(1,n*2-l+1,n*2) + 1*gs2(0,i+1,i+l) + 1*gs2(2,j+1,j+l);
            ans = max(ans, tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
