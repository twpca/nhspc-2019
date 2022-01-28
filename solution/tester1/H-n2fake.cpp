/**
 * O(n^2)
 *
 * This solution is WRONG with follwing example:
INPUT:
2 2
-2 -2
-81 -2
27 -2
69 -2
-31 0
-8 0
65 0
85 0
-57 2
-95 2
9 2
37 2

OUTPUT:
567

EXPECTED ANSWER:
572
*/
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
using namespace std;
int n,m;
int ll[3],rr[3];
deque<int> ar[3];

int work1(int x) {
    using P = pair<int,int>;
    int res = 0;
    priority_queue<P> q;
    
    auto push = [&](int id) {
        if (ll[id] >= rr[id]) return;
        q.push(make_pair( (ar[id][rr[id]] - ar[id][ll[id]])*4, id ));
    };
    
    push(0);
    push(2);
    while (x--) {
        auto tmp = q.top();
        q.pop();
        res += tmp.first;

        ll[tmp.second]++;
        rr[tmp.second]--;
        push(tmp.second);
    }
    return res;
}
int work2(int x) {
    using P = pair<int,int>;
    int res = 0;
    priority_queue<P> q;
    
    auto push = [&](int id) {
        if (ll[0] > rr[0]) return;
        if (ll[1] > rr[1]) return;
        if (ll[2] > rr[2]) return;

        if (id == 0) {
            q.push(make_pair(
                -2 * ar[0][ll[0]] - 2 * ar[2][ll[2]] + 4 * ar[1][rr[1]],
                0
            ));
        } else {
            q.push(make_pair(
                2 * ar[0][rr[0]] + 2 * ar[2][rr[2]] - 4 * ar[1][ll[1]],
                0
            ));
        }
    };

    push(0);
    push(1);
    while (x--) {
        auto tmp = q.top();
        q.pop();
        res += tmp.first;

        if (tmp.second==0) {
            ll[0]++;
            ll[2]++;
            rr[1]--;
        } else {
            rr[0]--;
            rr[2]--;
            ll[1]++;
        }
        push(tmp.second);
    }
    return res;
}
int work3(int x) {
    int res = 0;
    priority_queue<int> q;
    
    auto push = [&]() {
        if (ll[1] >= rr[1]) return;
        q.push(2*ar[1][rr[1]] - 2*ar[1][ll[1]]);
    };
    
    push();
    while (x--) {
        auto tmp = q.top();
        q.pop();
        res += tmp;

        ll[1]++;
        rr[1]--;

        push();
    }
    return res;
}
int main()
{
    while (~scanf("%d %d", &n,&m)) {
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
        

        int ans = 0;
        REP(i,0,n) REP(j,0,n-i) {
            REP(id,0,2) {
                ll[id] = 0;
                rr[id] = (int)ar[id].size() - 1;
            }

            int tmp = work1(i) + work2(j) + work3(n-i-j);
            ans = max(ans, tmp);
        }
        printf("%d\n", ans/2);
    }
    return 0;
}

