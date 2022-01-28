// O(n)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1000005
using namespace std;
using LL = long long;
int n,h[M],v[M];
int s[M],top;
LL dp[M],sv[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &h[i]);
        REP(i,1,n) scanf("%d", &v[i]);

        LL mx = 0;
        top = 0;
        REP(i,1,n) {
            while (top && h[s[top-1]] < h[i]) {
                mx = max(mx, dp[s[top-1]]);
                top--;
            }
            
            if (!top) dp[i] = v[i];
            else {
                if (top==1 && h[s[top-1]]==h[i])
                    dp[i] = v[i];
                else if (h[s[top-1]] == h[i])
                    dp[i] = sv[top-2] + v[i];
                else
                    dp[i] = sv[top-1] + v[i];
            }

            if (top && h[s[top-1]]==h[i]) {
                if (dp[i]>=dp[s[top-1]]) s[top-1] = i;
                sv[top-1] = mx;
            } else {
                s[top] = i;
                sv[top++] = mx;
            }
        }
        printf("%lld\n", *max_element(dp+1, dp+n+1));

        assert(*max_element(dp+1, dp+n+1) <= 2000000000LL);
    }
    return 0;
}
