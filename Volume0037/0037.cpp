#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
string ans = "URDL";
bool f[5][5][5];

int main() {

    memset(f,0,sizeof(f));

    rep(i,9) {
        int y = i/2;
    
        if(i%2 == 0) {
            string t;
            cin >> t;
    
            rep(j,4) {
                if(t[j] == '1') {
                    f[y][j][1] = true;
                    f[y][j+1][3] = true;
                }
            }
        } else {
            string t;
            cin >> t;
    
            rep(j,5) {
                if(t[j] == '1') {
                    f[y+1][j][0] = true;
                    f[y][j][2] = true;
                }
            }
        }
    }

    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};
    string ans = "URDL";
    int y = 0, x = 0, dir = 1;

    do {
        if(f[y][x][(dir+3)%4]) {
            dir = (dir+3)%4;
        } else if(f[y][x][dir]) {

        } else if(f[y][x][(dir+1)%4]) {
            dir = (dir+1)%4;
        } else if(f[y][x][(dir+2)%4]) {
            dir = (dir+2)%4;
        }


        y += dy[dir];
        x += dx[dir];
        cout << ans[dir];
    } while(y != 0 || x != 0);
    cout << endl;

    return 0;
}
