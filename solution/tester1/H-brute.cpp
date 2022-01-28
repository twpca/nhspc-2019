// A very slow solution but generates correct output
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 35
using namespace std;
int n,m,ans;
int x[M],y[M];
int vis[M];
int area(int a,int b,int c) {
    int res = x[a]*y[b] + x[b]*y[c] + x[c]*y[a]
        - y[a]*x[b] - y[b]*x[c] - y[c]*x[a];
    res = abs(res)/2;
    return res;
}
void dfs(int cur,int sum,int id) {
    if (cur>=6*n) {
        ans = max(ans, sum);

        /*if (sum==55) {
        REP(i,1,id-1) {
            REP(j,0,6*n-1) if(vis[j]==i) {
                printf("%d %d, ",x[j],y[j]);
            }
            puts("");
        }}*/
        return;
    }

    if (vis[cur]) {
        dfs(cur+1, sum, id);
        return;
    }

    REP(i,cur+1,6*n-1) if(!vis[i]) REP(j,i+1,6*n-1) if(!vis[j]) {
        vis[i] = vis[j] = vis[cur] = id;
        dfs(cur+1, sum + area(cur,i,j), id+1);
        vis[i] = vis[j] = vis[cur] = 0;
    }
}
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        ans = 0;
        REP(i,0,6*n-1) scanf("%d %d",&x[i],&y[i]);
        
        REP(i,0,(1<<(6*n))-1) {
            if (__builtin_popcount(i) != 3*n) continue;

            REP(j,0,6*n-1) {
                if((1<<j) & i) vis[j] = 0;
                else vis[j] = -1;
            }
            dfs(0, 0, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
