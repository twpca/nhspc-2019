#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n,cnt[M],col[M];
vector<int> e[M],lisan;

void init() {
    int x,y;
    MSET(cnt, 0);
    REP(i,0,M-1) e[i].clear();
    REP(i,1,n) scanf("%d",&col[i]);
    REP(i,1,n-1) {
        scanf("%d %d",&x,&y);
        x++;
        y++;
        e[x].push_back(y);
    }

    lisan.clear();
    REP(i,1,n) lisan.push_back(col[i]);
    sort(lisan.begin(), lisan.end());
    REP(i,1,n) col[i] = lower_bound(lisan.begin(), lisan.end(), col[i]) - lisan.begin() + 1;
}
int dfs(int cur) {
    cnt[col[cur]]++;
    int res = cnt[col[cur]];
    for (int i:e[cur]) res = max(res, dfs(i));
    cnt[col[cur]]--;
    return res;
}
int main()
{
    while (~scanf("%d", &n)) {
        init();
        printf("%d\n", dfs(1));
    }
    return 0;
}
