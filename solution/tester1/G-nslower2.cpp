// O(n), but more slower
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1000005
using namespace std;
using LL = long long;
int n,h[M],v[M];
LL dp[M];
stack<int> s;
stack<LL> sv;
int main()
{
    while (cin>>n) {
        REP(i,1,n) cin >> h[i];
        REP(i,1,n) cin >> v[i];

        s = stack<int>();
        sv = stack<LL>();
        LL mx = 0;
        REP(i,1,n) {
            while (!s.empty() && h[s.top()] < h[i]) {
                mx = max(mx, dp[s.top()]);
                s.pop();
                sv.pop();
            }
            
            if (s.empty()) dp[i] = v[i];
            else {
                if (s.size()==1 && h[s.top()]==h[i])
                    dp[i] = v[i];
                else if (h[s.top()] == h[i]) {
                    LL tmp = sv.top();
                    sv.pop();
                    dp[i] = sv.top() + v[i];
                    sv.push(tmp);
                }
                else
                    dp[i] = sv.top() + v[i];
            }

            if (!s.empty() && h[s.top()]==h[i]) {
                if (dp[i]>=dp[s.top()]) {
                    s.pop();
                    s.push(i);
                }
                sv.pop();
                sv.push(mx);
            } else {
                s.push(i);
                sv.push(mx);
            }
        }
        cout << *max_element(dp+1, dp+n+1) << endl;

        assert(*max_element(dp+1, dp+n+1) <= 2000000000LL);
    }
    return 0;
}
