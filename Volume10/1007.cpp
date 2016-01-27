#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int n;
    int id = 0;
    while(cin >> n && n) {
        int a[15][15];
        memset(a,0,sizeof(a));

        int b = 0, c = 0,v = 1;

        rep(i,n) {
            if(i % 2 == 0) {
                b = i;
                c = 0;

                a[b][c] = v;
                v++;

                while(!(b == 0 && c == i)) {
                    b--;
                    c++;

                    a[b][c] = v;
                    v++;
                }
            } else {
                b = 0;
                c = i;

                a[b][c] = v;
                v++;

                while(!(b == i && c == 0)) {
                    b++;
                    c--;

                    a[b][c] = v;
                    v++;
                }
            }
        }

        rep(i,n-1) {
            if(i % 2 == !(n%2)) {
                b = i + 1;
                c = n - 1;
        
                a[b][c] = v;
                v++;

                while(!(b == n - 1 && c ==  i + 1)) {
                    b++;
                    c--;
        
                    a[b][c] = v;
                    v++;
                }
            } else {
                b = n - 1;
                c = i + 1;
        
                a[b][c] = v;
                v++;

                while(!(b == i + 1 && c == n - 1)) {
                    b--;
                    c++;
        
                    a[b][c] = v;
                    v++;
                }
            }
        }

        cout << "Case " << id+1 << ":" << endl;
        id++;
        rep(i,n) {
            rep(j,n) {
                cout.width(3);
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
