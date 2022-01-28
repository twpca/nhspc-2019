// O(n^2 logn)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 10005
using namespace std;
using LL = long long;
int n;
LL sum[3][2*M],in[3][2*M];

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
        REP(i,0,n) REP(j,0,n-i) {
            int lim = n-i-j;
            int ok = lim;
            int ng = -1;
            int mid = 0;
            while (abs(ok-ng) > 1) {
                mid = (ok+ng)/2;
                int rr = lim-mid;
                LL left  = abs(in[0][i+mid+1]) + abs(in[2][j+mid+1]) + 2*abs(in[1][2*n-mid]); //llr not choose
                LL right = abs(in[0][2*n-i-rr+1]) + abs(in[2][2*n-j-rr+1]) + 2*abs(in[1][rr]); //rrl chosed

                if (left<=right) ok=mid;
                else ng=mid;
            }

            
            int l = ok; //llr
            int r = lim-ok; //rrl
            LL tmp = 2*gs(0,i) + 2*gs(2,j);
            tmp += 2*gs2(1,1,r) + gs2(0,2*n-i-r+1,2*n-i) + gs2(2,2*n-j-r+1,2*n-j);
            tmp += 2*gs2(1,2*n-l+1,2*n) + gs2(0,i+1,i+l) + gs2(2,j+1,j+l);
            ans = max(ans, tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
