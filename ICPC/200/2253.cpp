#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair

using namespace std;
typedef long long ll;

int dx[6] = {1,1,0,-1,-1,0};
int dy[6] = {0,1,1,0,-1,-1};

int main()
{
    int t,n;
    while(cin >> t >> n) {
        if(t == 0 && n == 0) break;
        

        int GETA = 100;
        bool used[200][200];
        memset(used,0,sizeof(used));

        rep(i,n) {
            int x,y;
            cin >> x >> y;
            
            used[y+GETA][x+GETA] = true;
        }

        queue<pair<pair<int,int>,int> > que;
        int sx,sy;
        cin >> sx >> sy;

        sy += GETA;
        sx += GETA;

        que.push(mp(mp(sy,sx),0));

        int ans = 1;
        used[sy][sx] = true;

        while(que.size()) {
            int y = que.front().first.first;
            int x = que.front().first.second;
            int cnt = que.front().second;
            que.pop();

            if(cnt < t) {
                rep(i,6) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(!used[ny][nx]) {
                        used[ny][nx] = true;
                        ans++;

                        // cout << ny << " " << nx << endl;
                        
                        que.push(mp(mp(ny,nx),cnt+1));
                    }
                }
            }
        }

        cout << ans << endl;
        
    }

    return 0;
}
