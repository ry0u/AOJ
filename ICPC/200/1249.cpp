#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int n,m,p;
int H[10][10];
int F[10][10][10];

int dx[13] = { 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1};
int dy[13] = { 0, 1, 0, 1,-1, 0, 0, 1, 1, 1, 1,-1,-1};
int dz[13] = { 0, 0, 1, 0, 0, 1,-1, 1,-1, 1,-1, 1,-1};

bool can(int x,int y,int z) {
    if(0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n) return true;
    return false;
}

int main() {
    while(cin >> n >> m >> p) {
        if(n == 0 && m == 0 && p == 0) break;
        
        memset(H,0,sizeof(H));
        memset(F,0,sizeof(F));

        bool flag = false;

        rep(q,p) {
            int x,y;
            cin >> x >> y;
            x--;
            y--;

            F[y][x][H[y][x]] = q%2 + 1;
            H[y][x]++;

            rep(i,n) {
                rep(j,n) {
                    rep(k,n) {
                        rep(l,13) {
                            int y = i;
                            int x = j;
                            int z = k;
                            int len = 0;

                            while(can(x,y,z) && F[y][x][z] == q%2 + 1) {
                                y += dy[l];
                                x += dx[l];
                                z += dz[l];
                                len++;
                            }
                            

                            if(len >= m && !flag) {
                                flag = true;
                                if(q%2 == 0) cout << "Black ";
                                else cout << "White ";
                                cout << q+1 << endl;
                            }
                        }
                    }
                }
            }
        }

        if(!flag) cout << "Draw" << endl;







    }

    return 0;
}
