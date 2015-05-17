#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,q;
    while(cin >> n >> q)
    {
        if(n == 0 && q == 0) break;

        int cnt[105];
        memset(cnt,0,sizeof(cnt));
        rep(i,n) {
            int m;
            cin >> m;

            rep(j,m) {
                int date;
                cin >> date;
                
                cnt[date]++;
            }
        }
        
        int vmax = 0;
        rep(i,105) vmax = max(vmax,cnt[i]);

        if(vmax < q) cout << 0 << endl;
        else {
            rep(i,105) {
                if(cnt[i] == vmax) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
