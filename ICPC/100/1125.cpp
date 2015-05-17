#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int w,h;
int F[505][505];

bool can(int y,int x) {
    if(0 <= y && y < h && 0 <= x && x < w) return true;
    return false;
}

int func(int y,int t,int x,int s) {
    int ret = 0;
    REP(i,y,y+t) {
        REP(j,x,x+s) {
            if(can(i,j)) {
                if(F[i][j]) ret++;
            }
            else return 0;
        }
    }

    return ret;
}

int main()
{
    int n;
    while(cin >> n && n)
    {
        cin >> w >> h;
        memset(F,0,sizeof(F));

        rep(i,n) {
            int x,y;
            cin >> x >> y;
            
            x--;
            y--;

            F[y][x]++;
        }

        int s,t;
        cin >> s >> t;

        int ans = 0;
        rep(i,h) {
            rep(j,w) {
                ans = max(ans,func(i,t,j,s));
            }
        }

        cout << ans << endl;
    }

    return 0;
}
