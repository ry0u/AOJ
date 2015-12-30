#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int w,h,n;
int sx,sy;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int F[15][15], id[15][15];

int dfs(int S, int y, int x) {

    if(__builtin_popcount(S) == n) {
        if(y == sy || x == sx) {
            return 1;
        }

        return 0;
    }

    int ret = 0;

    REP(i,y+1,h) {
        if(F[i][x] == 1) {
            if(S & (1<< id[i][x])) continue;
            else {
                ret += dfs(S | (1<<id[i][x]), i, x);
                break;
            }
        }
    }

    for(int i=y-1; i>=0; i--) {
        if(F[i][x] == 1) {
            if(S & (1<< id[i][x])) continue;
            else {
                ret += dfs(S | (1<<id[i][x]), i , x);
                break;
            }
        }
    }

REP(j,x+1,w) {
    if(F[y][j] == 1) {
        if(S & (1<<id[y][j])) continue;
        else {
            ret += dfs(S | (1<<id[y][j]), y, j);
            break;
        }
    }
}

for(int j=x-1; j>=0; j--) {
    if(F[y][j] == 1) {
        if(S & (1<<id[y][j])) continue;
        else {
            ret += dfs(S | (1<<id[y][j]), y , j);
            break;
        }
    }
}

return ret;
}
int main() {
    while(cin >> w >> h) {
        if(w == 0 && h == 0) break;

        memset(F,0,sizeof(F));
        memset(id,0,sizeof(id));
        n = 0;

        rep(i,h) {
            rep(j,w) {
                cin >> F[i][j];

                if(F[i][j] == 2) {
                    sy = i;
                    sx = j;
                } else if(F[i][j] == 1) {
                    id[i][j] = n;
                    n++;
                }
            }
        }

        vector<int> v;
        cout << dfs(0, sy, sx) << endl;
    }


    return 0;
}
