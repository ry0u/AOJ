#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n,w;
    while(cin >> n >> w) {
        if(n == 0 && w == 0) break;

        int cnt[1005];
        memset(cnt,0,sizeof(cnt));
        
        int seg = 0;
        rep(i,n) {
            int x;
            cin >> x;
            cnt[x/w]++;

            seg = max(seg,x/w);
        }

        int vmax = 0;
        rep(i,1005) {
            vmax = max(vmax,cnt[i]);
        }

        double ans = 0;
        rep(i,seg+1) {
            ans += (seg - i) /(double)seg * (cnt[i] / (double)vmax);
        }

        cout << fixed;
        cout.precision(10);
        cout << ans + 0.01 << endl;

    }

    return 0;
}
