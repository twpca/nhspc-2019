#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int t,n;
    int ans,fra,fr,cur;

    while (~scanf("%d %d", &t, &n)) {
        fra = 0;
        scanf("%d", &fr);
        ans = 1;

        REP(i,2,n) {
            scanf("%d", &cur);
            if (cur - fra > t) {
                ans++;
                fra = fr;
            }

            fr = cur;
        }
        printf("%d\n", ans);
    }
    return 0;
}
