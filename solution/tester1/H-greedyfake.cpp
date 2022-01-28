/**
 * O(n)
 * Stretegy: pick biggest triangle every step
 *
 * This solution is WRONG with follwing example:
INPUT:
2 2
-28 -2
-87 -2
5 -2
35 -2
-46 0
-73 0
81 0
56 0
-66 2
-38 2
6 2
76 2

OUTPUT:
528

EXPECTED:
572
*/
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
using namespace std;
int n,m;
deque<int> ar[3];
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
        REP(tt,1,n) {
            int aa[3], bb[2];
            REP(i,0,2) {
                aa[i] = ar[i].back() - ar[i].front();
                if (i==1) aa[i] *= 2;
                else aa[i] *= 4;
            }

            bb[0] = 2 * abs(abs(ar[0].front() + ar[2].front()) - 2*ar[1].back());
            bb[1] = 2 * abs(abs(ar[0].back()  + ar[2].back())  - 2*ar[1].front());
            //printf("%d %d %d\n",aa[0],aa[1],aa[2]);
            //printf("%d %d\n",bb[0],bb[1]);
            if (*max_element(aa, aa+3) >= *max_element(bb, bb+2)) {
                REP(i,0,2) if(aa[i] == *max_element(aa,aa+3)) {
                    ar[i].pop_front();
                    ar[i].pop_back();
                    break;
                }
            } else {
                if (bb[0] >= bb[1]) {
                    ar[0].pop_front();
                    ar[1].pop_back();
                    ar[2].pop_front();
                } else {
                    ar[0].pop_back();
                    ar[1].pop_front();
                    ar[2].pop_back();
                }
            }
            ans += max(*max_element(aa,aa+3), *max_element(bb,bb+2));
            //printf("ans=%d\n",ans);
        }
        printf("%d\n", ans/2);
    }
    return 0;
}
