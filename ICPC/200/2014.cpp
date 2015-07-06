#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

vector<string> v;
bool used[55][55];
int w,h,x,y;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool flag_W,flag_B;
int cnt;

bool can(int y,int x) {
    if(0 <= y && y < h && 0 <= x && x < w) return true;
    return false;
}

void dfs(int y,int x) {
    cnt++;
    rep(i,4) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(can(ny,nx)) {
            if(v[ny][nx] == 'W') flag_W = true;
            else if(v[ny][nx] == 'B') flag_B = true;
            else {
                if(!used[ny][nx]) {
                    used[ny][nx] = true;
                    dfs(ny,nx);
                }
            }
        }
    }
}

int main()
{
    while(cin >> w >> h) {
        if(w == 0 && h == 0) break;
        
        v.clear();
        v.resize(h);
        rep(i,h) cin >> v[i];

        memset(used,0,sizeof(used));
        int a = 0,b = 0;
        rep(i,h) {
            rep(j,w) {
                if(!used[i][j] && v[i][j] == '.') {
                    flag_W = false;
                    flag_B = false;
                    cnt = 0;
                    used[i][j] = true;

                    dfs(i,j);
                    if(flag_B && !flag_W) a += cnt;
                    if(flag_W && !flag_B) b += cnt;
                }
            }
        }

        cout << a << " " << b << endl;

    }

    return 0;
}
