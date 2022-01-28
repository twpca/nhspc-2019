// O(n)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1000005
using namespace std;
using LL = long long;
int n,lh[M],rh[M];
LL in[M],ans[M];
void dfs(int l,int r,LL water,int st) {
    if (water==0) return;

    //printf("l=%d r=%d water=%lld st=%d\n",l,r,water,st);

    int lc = st;
    int rc = st+1;
    LL h;
    int frl = st;
    int frr = st+1;
    LL frh = 0;
    while (1) {
        h = min(in[lc], in[rc]);
        if (h * (rc-lc) > water) break;
        if (lc==l && rc==r) break;

        frl = lc;
        frr = rc;
        frh = h;
        
        if (in[lc]<=h) lc = lh[lc];
        if (in[rc]<=h) rc = rh[rc];
    }
    //printf("frlc=%d frrc=%d frh=%lld\n",frl,frr,frh);

    if (rc-lc==1) {
        ans[lc] = water;
        return;
    }
    if (frh * (rc-lc) <= water) {
        h = water / (rc-lc);
        assert(water % (rc-lc) == 0);
        REP(i,lc,rc-1) ans[i] = h;
        return;
    }
    
    REP(i,frl,frr-1) ans[i] = frh;
    water -= (frr-frl) * frh;
    if (in[frl] == in[frr]) assert(0);
    if (in[frl] == frh) {
        dfs(l,frl,water,frl-1);
    }
    if (in[frr] == frh) {
        dfs(frr,r,water,frr);
    }
}
int main()
{
    int st;
    LL tot;
    while (~scanf("%d %d %lld", &n, &st, &tot)) {
        st++;
        
        REP(i,1,n) scanf("%lld", &in[i]);

        {
            int top = 0;
            vector<int> s(n+1);
            REP(i,1,n) {
                while (top && in[s[top-1]] < in[i]) top--;
                lh[i] = top ? s[top-1] : 0;
                s[top++] = i;
            }

            top = 0;
            for (int i=n; i>=1; i--) {
                while (top && in[s[top-1]] < in[i]) top--;
                rh[i] = top ? s[top-1] : n+1;
                s[top++] = i;
            }
        }
        
        
        MSET(ans, 0);
        dfs(1, n, tot, st);

        REP(i,1,n-1) printf("%lld%c", ans[i], i==n-1 ? '\n' : ' ');
        assert(accumulate(ans+1, ans+n, 0LL) == tot);
    }
    return 0;
}
