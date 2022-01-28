// O(n^2)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 605
using namespace std;
int n,in[M],pos[M];
int mni[M][M], mxi[M][M];
int mnp[M][M], mxp[M][M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) {
            scanf("%d", &in[i]);
            pos[in[i]] = i;
        }

        REP(i,1,n)REP(j,i,n) {
            if (i==j) {
                mnp[i][j] = mxp[i][j] = pos[i];
                mni[i][j] = mxi[i][j] = in[i];
            } else {
                mnp[i][j] = min(mnp[i][j-1], pos[j]);
                mxp[i][j] = max(mxp[i][j-1], pos[j]);
                mni[i][j] = min(mni[i][j-1], in[j]);
                mxi[i][j] = max(mxi[i][j-1], in[j]);
            }
        }

        auto find_range = [&](int x,int y) {
            return make_pair(mnp[x][y], mxp[x][y]);
        };
        auto check_numbers = [&](int l,int r,int x,int y) {
            // are numbers in [l,r] range in [x,y]?
            if (l>r) return false;
            return mxi[l][r]<=y && mni[l][r]>=x;
        };
        auto check_ans = [&](int i,int j,int l1,int r1,int l2,int r2) {
            if (l1>r1 || l2>r2) return false;
            if (l1<=0 || r1>n) return false;
            if (l2<=0 || r2>n) return false;
            return check_numbers(l1,r1,i,j) && check_numbers(l2,r2,i,j) &&
                r1-l1+r2-l2+2 == j-i+1 &&
                (l1>r2 || l2>r1);
        };
       
        int ans = 0;
        REP(i,1,n)REP(j,i+1,n) {
            int ll,rr,l1,r1,l2,r2,nokori;
            tie(ll,rr) = find_range(i, j);
            if (rr-ll+1 == j-i+1 && ll==min(pos[i],pos[j]) && rr==max(pos[i],pos[j])) continue;

            // case 1
            l1 = ll;
            r1 = min(pos[i], pos[j]);
            nokori = (j-i+1) - (r1-l1+1);
            r2 = max(pos[i], pos[j]);
            l2 = r2 - nokori + 1;
            if (check_ans(i,j,l1,r1,l2,r2)) {
                ans++;
                continue;
            }

            // case 1.5
            l1 = ll;
            r1 = l1;
            nokori = (j-i+1) - (r1-l1+1);
            l2 = max(pos[i], pos[j]);
            r2 = l2 + nokori - 1;
            if (check_ans(i,j,l1,r1,l2,r2)) {
                ans++;
                continue;
            }

            // case 2
            r2 = rr;
            l2 = max(pos[i], pos[j]);
            nokori = (j-i+1) - (r2-l2+1);
            l1 = min(pos[i], pos[j]);
            r1 = l1 + nokori - 1;
            if (check_ans(i,j,l1,r1,l2,r2)) {
                ans++;
                continue;
            }

            // case 2.5
            r2 = rr;
            l2 = r2;
            nokori = (j-i+1) - (r2-l2+1);
            r1 = min(pos[i], pos[j]);
            l1 = r1 - nokori + 1;
            if (check_ans(i,j,l1,r1,l2,r2)) {
                ans++;
                continue;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
