// O(min(n^2m, nm^2) * log (n+m))
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
using namespace std;
int k,n,m;
vector<vector<int>> in, dp;
void init() {
    if (n<=m) {
        in = vector<vector<int>> (n+1);
        dp = vector<vector<int>> (n+1);
        REP(i,0,n) in[i] = vector<int> (m+1);
        REP(i,0,n) dp[i] = vector<int> (m+1);
    } else {
        in = vector<vector<int>> (m+1);
        dp = vector<vector<int>> (m+1);
        REP(i,0,m) in[i] = vector<int> (n+1);
        REP(i,0,m) dp[i] = vector<int> (n+1);
    }

    int x;
    REP(i,1,n) REP(j,1,m) {
        scanf("%d", &x);
        if (n<=m) in[i][j] = x;
        else in[j][i] = x;
    }
    if (n > m) swap(n,m);

    REP(i,1,n) REP(j,1,m) dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + in[i][j];
}
int s2(int x1,int x2,int y1,int y2) {
    x1--;
    y1--;
    return dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1];
}
int work() {
    int res = -INF;
    set<int> s;

    REP(i1,1,n) REP(i2,i1,n) {
        s.clear();
        s.insert(0);
        REP(j,1,m) {
            int num = s2(i1,i2,1,j);
            auto it = s.lower_bound(num-k);
            if (it!=s.end()) res = max(res, num-*it);
            s.insert(num);
        }
    }
    assert(res != -INF);
    return res;
}

int main()
{
    while (~scanf("%d %d %d", &k, &n, &m)) {
        init();
        printf("%d\n", work());
    }
    return 0;
}
